from __future__ import annotations

import functools
import json
import logging
import math
import os
from einops import rearrange, einsum
import einx
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch import Tensor
from jaxtyping import Float, Bool, Int

# Import ready-made functions from adapters.py
from tests.adapters import (
    run_linear,
    run_embedding,
    run_rmsnorm,
    run_swiglu,
    run_transformer_block,
    run_softmax,
    run_multihead_self_attention_with_rope,
    run_rope
)

logger = logging.getLogger(__name__)

class Linear(nn.Module):
    def __init__(self, d_in: int, d_out: int):
        """A linear layer initialized with truncated normal fan-in fan-out.

        Args:
            d_in: int
                The number of input features.
            d_out: int
                The number of output features.
        """  
        super().__init__()
        std = math.sqrt(2 / (d_in + d_out))
        self.weight: Float[Tensor, " d_out d_in"] = nn.Parameter(
            nn.init.trunc_normal_(torch.empty(d_out, d_in), std=std, a=-3*std, b=3*std),
            requires_grad=True
        )

    def forward(self, x: Float[Tensor, " ... d_in"]) -> Float[Tensor, " ... d_out"]:
        d_in = self.weight.shape[1]
        d_out = self.weight.shape[0]
        return run_linear(d_in, d_out, self.weight, x)
    
    def extra_repr(self):
        return f"d_out={self.weight.shape[0]}, d_in={self.weight.shape[1]}"


class Embedding(nn.Module):
    def __init__(self, vocab_size: int, d_model: int):
        super().__init__()
        std = 1.0
        self.weight = nn.Parameter(
            nn.init.trunc_normal_(torch.empty(vocab_size, d_model), std=std, a=-3 * std, b=3 * std),
            requires_grad=True
        )
    
    def forward(self, token_ids: Int[Tensor, " ..."]) -> Float[Tensor, " ... d_model"]:
        vocab_size = self.weight.shape[0]
        d_model = self.weight.shape[1]
        return run_embedding(vocab_size, d_model, self.weight, token_ids)
    
    def extra_repr(self):
        return f"vocab_size={self.weight.shape[0]}, d={self.weight.shape[1]}"


class RMSNorm(nn.Module):
    """
    This module implements root mean square layer normalization, as
    described in Eq. 4 of https://arxiv.org/abs/1910.07467

    Args:
        hidden_size: int
            Dimensionality of the input to normalize.
        eps: float, default is 1e-5
            A value added to the denominator for numerical stability.

    Returns:
        FloatTensor of same shape as input.
    """
    def __init__(self, hidden_size: int, eps: float = 1e-5,device=None):
        super().__init__()
        self.weight = nn.Parameter(torch.ones(hidden_size, device=device))
        self.eps = eps

    def forward(self, x):
        d_model = self.weight.shape[0]
        return run_rmsnorm(d_model, self.eps, self.weight, x)
    
    def extra_repr(self):
        return f"hidden_size={self.weight.shape[0]}, eps={self.eps}"


class LSTMNetwork(nn.Module):
    """LSTM Language Model to replace Transformer"""

    def __init__(self, vocab_size: int, context_length: int, d_model: int, num_layers: int, num_heads: int = None, d_ff: int = None, rope_theta: float = None):
        super().__init__()
        
        # Store configuration
        self.config = {
            'vocab_size': vocab_size,
            'context_length': context_length,
            'd_model': d_model,
            'num_layers': num_layers,
            'num_heads': num_heads,
            'd_ff': d_ff,
            'rope_theta': rope_theta
        }
        
        self.vocab_size = vocab_size
        self.context_length = context_length
        self.d_model = d_model
        self.num_layers = num_layers
        
        # LSTM layers
        self.embedding = Embedding(vocab_size, d_model)
        self.lstm = nn.LSTM(d_model, d_model, num_layers, dropout=0.1, batch_first=True)
        
        # Output layers with dropout
        self.output_layers = nn.Sequential(
            nn.Dropout(0.2),
            Linear(d_model, 512),
            nn.Dropout(0.2),
            Linear(512, 256),
            nn.Dropout(0.2),
            Linear(256, vocab_size)
        )
        
        logger.info(f"LSTM Model Parameters: {self.get_num_params() / 1e6:.2f}M")

    def get_num_params(self, non_embedding=True):
        """Return the number of parameters in the model."""
        n_params = sum(p.numel() for p in self.parameters())
        if non_embedding:
            n_params -= self.embedding.weight.numel()
            # Also subtract output layer parameters if needed
            n_params -= sum(p.numel() for p in self.output_layers.parameters())
        return n_params

    def forward(self, x: Int[Tensor, "batch sequence_length"], state: tuple = None) -> Float[Tensor, "batch sequence_length vocab_size"]:
        """
        Args:
            x: Input IDs for language modeling.
            state: Tuple of (hidden_state, cell_state) for LSTM

        Returns: 
            logits: FloatTensor of shape (batch size, sequence_length, vocab_size)
            state: Updated LSTM state
        """
        batch_size, seq_len = x.shape
        
        # Get embeddings
        x_emb = self.embedding(x)  # (batch, seq_len, d_model)
        
        # Initialize state if not provided
        if state is None:
            h0 = torch.zeros(self.num_layers, batch_size, self.d_model, device=x.device)
            c0 = torch.zeros(self.num_layers, batch_size, self.d_model, device=x.device)
            state = (h0, c0)
        
        # LSTM forward pass
        lstm_out, new_state = self.lstm(x_emb, state)  # (batch, seq_len, d_model)
        
        # Apply output layers
        logits = self.output_layers(lstm_out)  # (batch, seq_len, vocab_size)
        
        return logits, new_state

    @torch.no_grad()
    def generate(self, x: torch.Tensor, max_new_tokens: int, temperature: float = 1.0, top_k: int | None = None, eos_token_id: int | None = None):
        """
        Args:
            x: LongTensor of shape `(1, sequence_length,)` or `(sequence_length, )`.
                Input IDs to condition on when generating.
            max_new_tokens: int
                Maximum number of tokens to generate.
            temperature: float
                Temperature to use during generation.
            top_k: int
                If provided, only sample from the `top_k` vocab items (by probability).
            eos_token_id: int
                If provided, stop generation when we generate this ID.

        Returns: A LongTensor of shape (max_new_tokens,) with the generated model output.
        """
        if x.dim() == 1:
            x = x.unsqueeze(0)
        
        original_sequence_length = x.size(-1)
        batch_size = x.size(0)
        
        # Initialize LSTM state
        state = None
        generated_tokens = []
        
        for _ in range(max_new_tokens):
            # Take the last `context_length` tokens if the input is beyond context length
            if x.size(1) > self.context_length:
                x = x[:, -self.context_length:]
            
            # Get the logits from the model
            logits, state = self.forward(x, state)
            
            # Take the logits for the next token (last token in sequence)
            next_token_logits = logits[:, -1]  # (batch, vocab_size)
            
            # Apply temperature scaling
            temperature_scaled_next_token_logits = next_token_logits / temperature
            
            # If top-k is provided, take the tokens with the highest score
            if top_k:
                topk_values, _ = torch.topk(
                    temperature_scaled_next_token_logits,
                    min(top_k, temperature_scaled_next_token_logits.size(-1)),
                )
                threshold = topk_values[:, -1]
                topk_mask = temperature_scaled_next_token_logits < threshold
                temperature_scaled_next_token_logits.masked_fill(topk_mask, float("-inf"))
            
            # Get probabilities and sample
            next_token_probabilities = run_softmax(temperature_scaled_next_token_logits, dim=-1)
            next_token_id = torch.multinomial(next_token_probabilities, 1)
            
            # End generation if we see the EOS token ID
            if eos_token_id is not None and next_token_id.item() == eos_token_id:
                break
                
            generated_tokens.append(next_token_id)
            x = torch.cat((x, next_token_id), dim=-1)
        
        new_token_ids = torch.cat(generated_tokens, dim=-1)
        return new_token_ids

    @classmethod
    def from_pretrained(cls, pretrained_model_path: str):
        config_path = os.path.join(pretrained_model_path, "model_config.json")
        with open(config_path) as f:
            config = json.load(f)
        model = cls(**config)
        weights_path = os.path.join(pretrained_model_path, "model.pt")
        state_dict = torch.load(weights_path)
        # Remove _orig_mod. prefix that comes from serializing a compiled model
        unwanted_prefix = "_orig_mod."
        for k, _ in list(state_dict.items()):
            if k.startswith(unwanted_prefix):
                state_dict[k[len(unwanted_prefix) :]] = state_dict.pop(k)
        model.load_state_dict(state_dict)
        return model


# For backward compatibility, alias LSTMNetwork as BasicsTransformerLM
BasicsTransformerLM = LSTMNetwork