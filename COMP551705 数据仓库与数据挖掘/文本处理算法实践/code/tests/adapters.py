from __future__ import annotations
from collections import defaultdict
import os
from collections.abc import Iterable
from typing import IO, Any, BinaryIO, Dict
import numpy.typing as npt
import torch
from jaxtyping import Bool, Float, Int
from torch import Tensor
import regex as re
from typing import Iterator
import regex as re_module

PAT = r"""'(?:[sdmt]|ll|ve|re)| ?\p{L}+| ?\p{N}+| ?[^\s\p{L}\p{N}]+|\s+(?!\S)|\s+"""

def run_linear(
    d_in: int,
    d_out: int,
    weights: Float[Tensor, " d_out d_in"],
    in_features: Float[Tensor, " ... d_in"],
) -> Float[Tensor, " ... d_out"]:
    """
    Given the weights of a Linear layer, compute the transformation of a batched input.

    Args:
        in_dim (int): The size of the input dimension
        out_dim (int): The size of the output dimension
        weights (Float[Tensor, "d_out d_in"]): The linear weights to use
        in_features (Float[Tensor, "... d_in"]): The output tensor to apply the function to

    Returns:
        Float[Tensor, "... d_out"]: The transformed output of your linear module.
    """
    return torch.matmul(in_features, weights.T)
    #raise NotImplementedError


def run_embedding(
    vocab_size: int,
    d_model: int,
    weights: Float[Tensor, " vocab_size d_model"],
    token_ids: Int[Tensor, " ..."],
) -> Float[Tensor, " ... d_model"]:
    """
    Given the weights of an Embedding layer, get the embeddings for a batch of token ids.

    Args:
        vocab_size (int): The number of embeddings in the vocabulary
        d_model (int): The size of the embedding dimension
        weights (Float[Tensor, "vocab_size d_model"]): The embedding vectors to fetch from
        token_ids (Int[Tensor, "..."]): The set of token ids to fetch from the Embedding layer

    Returns:
        Float[Tensor, "... d_model"]: Batch of embeddings returned by your Embedding layer.
    """
    return weights[token_ids]
    #raise NotImplementedError


def run_swiglu(
    d_model: int,
    d_ff: int,
    w1_weight: Float[Tensor, " d_ff d_model"],
    w2_weight: Float[Tensor, " d_model d_ff"],
    w3_weight: Float[Tensor, " d_ff d_model"],
    in_features: Float[Tensor, " ... d_model"],
) -> Float[Tensor, " ... d_model"]:
    """Given the weights of a SwiGLU network, return
    the output of your implementation with these weights.

    Args:
        d_model (int): Dimensionality of the feedforward input and output.
        d_ff (int): Dimensionality of the up-project happening internally to your swiglu.
        w1_weight (Float[Tensor, "d_ff d_model"]): Stored weights for W1
        w2_weight (Float[Tensor, "d_model d_ff"]): Stored weights for W2
        w3_weight (Float[Tensor, "d_ff d_model"]): Stored weights for W3
        in_features (Float[Tensor, "... d_model"]): Input embeddings to the feed-forward layer.

    Returns:
        Float[Tensor, "... d_model"]: Output embeddings of the same shape as the input embeddings.
    """
    # Example:
    # If your state dict keys match, you can use `load_state_dict()`
    # swiglu.load_state_dict(weights)
    # You can also manually assign the weights
    # swiglu.w1.weight.data = w1_weight
    # swiglu.w2.weight.data = w2_weight
    # swiglu.w3.weight.data = w3_weight
    gate = run_silu(torch.matmul(in_features, w1_weight.T))
    value = torch.matmul(in_features, w3_weight.T)
    output = torch.matmul(gate * value, w2_weight.T)
    return output
    #raise NotImplementedError


def run_scaled_dot_product_attention(
    Q: Float[Tensor, " ... queries d_k"],
    K: Float[Tensor, " ... keys d_k"],
    V: Float[Tensor, " ... values d_v"],
    mask: Bool[Tensor, " ... queries keys"] | None = None,
) -> Float[Tensor, " ... queries d_v"]:
    """
    Given key (K), query (Q), and value (V) tensors, return
    the output of your scaled dot product attention implementation.

    Args:
        Q (Float[Tensor, " ... queries d_k"]): Query tensor
        K (Float[Tensor, " ... keys d_k"]): Key tensor
        V (Float[Tensor, " ... values d_v"]): Values tensor
        mask (Bool[Tensor, " ... queries keys"] | None): Mask tensor
    Returns:
        Float[Tensor, " ... queries d_v"]: Output of SDPA
    """
    d_k = Q.size(-1)
    scores = torch.matmul(Q, K.transpose(-2, -1)) / (d_k ** 0.5)
    if mask is not None:
        scores = scores.masked_fill(mask == False, float('-inf'))
    attention_weights = run_softmax(scores, dim=-1)
    output = torch.matmul(attention_weights, V)
    return output
    #raise NotImplementedError


def run_multihead_self_attention(
    d_model: int,
    num_heads: int,
    q_proj_weight: Float[Tensor, " d_k d_in"],
    k_proj_weight: Float[Tensor, " d_k d_in"],
    v_proj_weight: Float[Tensor, " d_v d_in"],
    o_proj_weight: Float[Tensor, " d_model d_v"],
    in_features: Float[Tensor, " ... sequence_length d_in"],
) -> Float[Tensor, " ... sequence_length d_out"]:
    """
    Given the key, query, and value projection weights of a naive unbatched
    implementation of multi-head attention, return the output of an optimized batched
    implementation. This implementation should handle the key, query, and value projections
    for all heads in a single matrix multiply.
    This function should not use RoPE.
    See section 3.2.2 of Vaswani et al., 2017.

    Args:
        d_model (int): Dimensionality of the feedforward input and output.
        num_heads (int): Number of heads to use in multi-headed attention.
        max_seq_len (int): Maximum sequence length to pre-cache if your implementation does that.
        q_proj_weight (Float[Tensor, "d_k d_in"]): Weights for the Q projection
        k_proj_weight (Float[Tensor, "d_k d_in"]): Weights for the K projection
        v_proj_weight (Float[Tensor, "d_k d_in"]): Weights for the V projection
        o_proj_weight (Float[Tensor, "d_model d_v"]): Weights for the output projection
        in_features (Float[Tensor, "... sequence_length d_in"]): Tensor to run your implementation on.

    Returns:
        Float[Tensor, " ... sequence_length d_out"]: Tensor with the output of running your optimized, batched multi-headed attention
        implementation with the given QKV projection weights and input features.
    """
    batch_size, seq_len, d_in = in_features.shape
    d_k = d_model // num_heads
    d_v = d_model // num_heads
    Q = torch.matmul(in_features, q_proj_weight.T)
    K = torch.matmul(in_features, k_proj_weight.T)
    V = torch.matmul(in_features, v_proj_weight.T)
    Q = Q.view(batch_size, seq_len, num_heads, d_k).transpose(1, 2)
    K = K.view(batch_size, seq_len, num_heads, d_k).transpose(1, 2)
    V = V.view(batch_size, seq_len, num_heads, d_v).transpose(1, 2)
    d_k_scalar = Q.size(-1)
    scores = torch.matmul(Q, K.transpose(-2, -1)) / (d_k_scalar ** 0.5)
    mask = torch.triu(torch.ones(seq_len, seq_len, device=in_features.device) * float('-inf'), diagonal=1)
    scores = scores + mask
    attention_weights = run_softmax(scores, dim=-1)
    attention_output = torch.matmul(attention_weights, V) 
    attention_output = attention_output.transpose(1, 2).contiguous().view(batch_size, seq_len, d_model)
    output = torch.matmul(attention_output, o_proj_weight.T)
    return output
    #raise NotImplementedError


def run_multihead_self_attention_with_rope(
    d_model: int,
    num_heads: int,
    max_seq_len: int,
    theta: float,
    q_proj_weight: Float[Tensor, " d_k d_in"],
    k_proj_weight: Float[Tensor, " d_k d_in"],
    v_proj_weight: Float[Tensor, " d_v d_in"],
    o_proj_weight: Float[Tensor, " d_model d_v"],
    in_features: Float[Tensor, " ... sequence_length d_in"],
    token_positions: Int[Tensor, " ... sequence_length"] | None = None,
) -> Float[Tensor, " ... sequence_length d_out"]:
    """
    Given the key, query, and value projection weights of a naive unbatched
    implementation of multi-head attention, return the output of an optimized batched
    implementation. This implementation should handle the key, query, and value projections
    for all heads in a single matrix multiply.
    This version of MHA should include RoPE.
    In this case, the RoPE embedding dimension must be the head embedding dimension (d_model // num_heads).
    See section 3.2.2 of Vaswani et al., 2017.

    Args:
        d_model (int): Dimensionality of the feedforward input and output.
        num_heads (int): Number of heads to use in multi-headed attention.
        max_seq_len (int): Maximum sequence length to pre-cache if your implementation does that.
        theta (float): RoPE parameter.
        q_proj_weight (Float[Tensor, "d_k d_in"]): Weights for the Q projection
        k_proj_weight (Float[Tensor, "d_k d_in"]): Weights for the K projection
        v_proj_weight (Float[Tensor, "d_k d_in"]): Weights for the V projection
        o_proj_weight (Float[Tensor, "d_model d_v"]): Weights for the output projection
        in_features (Float[Tensor, "... sequence_length d_in"]): Tensor to run your implementation on.
        token_positions (Int[Tensor, " ... sequence_length"] | None): Optional tensor with the positions of the tokens

    Returns:
        Float[Tensor, " ... sequence_length d_out"]: Tensor with the output of running your optimized, batched multi-headed attention
        implementation with the given QKV projection weights and input features.
    """
    batch_size, seq_len, d_in = in_features.shape
    if token_positions is None:
        token_positions = torch.arange(seq_len, device=in_features.device).unsqueeze(0).expand(batch_size, seq_len) 
    head_dim = d_model // num_heads
    Q = torch.matmul(in_features, q_proj_weight.T)
    K = torch.matmul(in_features, k_proj_weight.T)
    V = torch.matmul(in_features, v_proj_weight.T)
    Q = Q.view(batch_size, seq_len, num_heads, head_dim).transpose(1, 2)
    K = K.view(batch_size, seq_len, num_heads, head_dim).transpose(1, 2)
    V = V.view(batch_size, seq_len, num_heads, head_dim).transpose(1, 2)
    Q_reshaped = Q.reshape(batch_size * num_heads, seq_len, head_dim)
    K_reshaped = K.reshape(batch_size * num_heads, seq_len, head_dim)
    token_positions_expanded = token_positions.unsqueeze(1).expand(batch_size, num_heads, seq_len)
    token_positions_expanded = token_positions_expanded.reshape(batch_size * num_heads, seq_len)
    Q_rope = run_rope(head_dim, theta, max_seq_len, Q_reshaped, token_positions_expanded)
    K_rope = run_rope(head_dim, theta, max_seq_len, K_reshaped, token_positions_expanded)
    Q_rope = Q_rope.reshape(batch_size, num_heads, seq_len, head_dim)
    K_rope = K_rope.reshape(batch_size, num_heads, seq_len, head_dim)
    attention_scores = torch.matmul(Q_rope, K_rope.transpose(-2, -1)) / (head_dim ** 0.5)
    causal_mask = torch.triu(
        torch.full((seq_len, seq_len), float('-inf'), device=in_features.device), 
        diagonal=1
    ).unsqueeze(0).unsqueeze(0)
    attention_scores = attention_scores + causal_mask
    attention_weights = run_softmax(attention_scores, dim=-1)
    attention_output = torch.matmul(attention_weights, V)
    attention_output = attention_output.transpose(1, 2).contiguous()
    attention_output = attention_output.view(batch_size, seq_len, d_model)
    output = torch.matmul(attention_output, o_proj_weight.T) 
    return output
    #raise NotImplementedError


def run_rope(
    d_k: int,
    theta: float,
    max_seq_len: int,
    in_query_or_key: Float[Tensor, " ... sequence_length d_k"],
    token_positions: Int[Tensor, " ... sequence_length"],
) -> Float[Tensor, " ... sequence_length d_k"]:
    """
    Run RoPE for a given input tensor.

    Args:
        d_k (int): Embedding dimension size for the query or key tensor.
        theta (float): RoPE parameter.
        max_seq_len (int): Maximum sequence length to pre-cache if your implementation does that.
        in_query_or_key (Float[Tensor, "... sequence_length d_k"]): Input tensor to run RoPE on.
        token_positions (Int[Tensor, "... sequence_length"]): Tensor of shape (batch_size, sequence_length) with the token positions
    Returns:
        Float[Tensor, " ... sequence_length d_k"]: Tensor with RoPEd input.
    """
    batch_size, seq_len, d_k = in_query_or_key.shape
    x = in_query_or_key.reshape(batch_size, seq_len, d_k // 2, 2)
    if token_positions.dim() == 1:
        token_positions = token_positions.unsqueeze(0).expand(batch_size, seq_len)
    freqs = 1.0 / (theta ** (torch.arange(0, d_k, 2, dtype=torch.float32, device=in_query_or_key.device) / d_k))
    positions = token_positions.unsqueeze(-1).float()
    angles = positions * freqs
    cos = torch.cos(angles).unsqueeze(-1)
    sin = torch.sin(angles).unsqueeze(-1)
    x1 = x[..., 0:1] 
    x2 = x[..., 1:2]
    rotated_x1 = x1 * cos - x2 * sin
    rotated_x2 = x1 * sin + x2 * cos
    result = torch.cat([rotated_x1, rotated_x2], dim=-1)
    result = result.reshape(batch_size, seq_len, d_k)
    return result
    #raise NotImplementedError


def run_transformer_block(
    d_model: int,
    num_heads: int,
    d_ff: int,
    max_seq_len: int,
    theta: float,
    weights: dict[str, Tensor],
    in_features: Float[Tensor, " batch sequence_length d_model"],
) -> Float[Tensor, " batch sequence_length d_model"]:
    """
    Given the weights of a pre-norm Transformer block and input features,
    return the output of running the Transformer block on the input features.

    This function should use RoPE.
    Depending on your implementation, you may simply need to pass the relevant args
    to your TransformerBlock constructor, or you may need to initialize your own RoPE
    class and pass that instead.

    Args:
        d_model (int): The dimensionality of the Transformer block input.
        num_heads (int): Number of heads to use in multi-headed attention. `d_model` must be
            evenly divisible by `num_heads`.
        d_ff (int): Dimensionality of the feed-forward inner layer.
        max_seq_len (int): Maximum sequence length to pre-cache if your implementation does that.
        theta (float): RoPE parameter.
        weights (dict[str, Tensor]):
            State dict of our reference implementation.
            The keys of this dictionary are:
            - `attn.q_proj.weight`
                The query projections for all `num_heads` attention heads.
                Shape is (d_model, d_model).
                The rows are ordered by matrices of shape (num_heads, d_k),
                so `attn.q_proj.weight == torch.cat([q_heads.0.weight, ..., q_heads.N.weight], dim=0)`.
            - `attn.k_proj.weight`
                The key projections for all `num_heads` attention heads.
                Shape is (d_model, d_model).
                The rows are ordered by matrices of shape (num_heads, d_k),
                so `attn.k_proj.weight == torch.cat([k_heads.0.weight, ..., k_heads.N.weight], dim=0)`.
            - `attn.v_proj.weight`
                The value projections for all `num_heads` attention heads.
                Shape is (d_model, d_model).
                The rows are ordered by matrices of shape (num_heads, d_v),
                so `attn.v_proj.weight == torch.cat([v_heads.0.weight, ..., v_heads.N.weight], dim=0)`.
            - `attn.output_proj.weight`
                Weight of the multi-head self-attention output projection
                Shape is (d_model, d_model).
            - `ln1.weight`
                Weights of affine transform for the first RMSNorm
                applied in the transformer block.
                Shape is (d_model,).
            - `ffn.w1.weight`
                Weight of the first linear transformation in the FFN.
                Shape is (d_model, d_ff).
            - `ffn.w2.weight`
                Weight of the second linear transformation in the FFN.
                Shape is (d_ff, d_model).
            - `ffn.w3.weight`
                Weight of the third linear transformation in the FFN.
                Shape is (d_model, d_ff).
            - `ln2.weight`
                Weights of affine transform for the second RMSNorm
                applied in the transformer block.
                Shape is (d_model,).
        in_features (Float[Tensor, "batch sequence_length d_model"]):
            Tensor to run your implementation on.

    Returns:
        Float[Tensor, "batch sequence_length d_model"] Tensor with the output of
        running the Transformer block on the input features while using RoPE.
    """
    x = run_rmsnorm(d_model, 1e-5, weights['ln1.weight'], in_features)
    x_attn = run_multihead_self_attention_with_rope(
        d_model, num_heads, max_seq_len, theta,
        weights['attn.q_proj.weight'], weights['attn.k_proj.weight'], 
        weights['attn.v_proj.weight'], weights['attn.output_proj.weight'],
        x
    )
    x = in_features + x_attn
    x_norm = run_rmsnorm(d_model, 1e-5, weights['ln2.weight'], x)
    x_ffn = run_swiglu(
        d_model, d_ff,
        weights['ffn.w1.weight'], weights['ffn.w2.weight'], weights['ffn.w3.weight'],
        x_norm
    )
    x = x + x_ffn
    return x
    #raise NotImplementedError


def run_transformer_lm(
    vocab_size: int,
    context_length: int,
    d_model: int,
    num_layers: int,
    num_heads: int,
    d_ff: int,
    rope_theta: float,
    weights: dict[str, Tensor],
    in_indices: Int[Tensor, " batch_size sequence_length"],
) -> Float[Tensor, " batch_size sequence_length vocab_size"]:
    """Given the weights of a Transformer language model and input indices,
    return the output of running a forward pass on the input indices.

    This function should use RoPE.

    Args:
        vocab_size (int): The number of unique items in the output vocabulary to be predicted.
        context_length (int): The maximum number of tokens to process at once.
        d_model (int): The dimensionality of the model embeddings and sublayer outputs.
        num_layers (int): The number of Transformer layers to use.
        num_heads (int): Number of heads to use in multi-headed attention. `d_model` must be
            evenly divisible by `num_heads`.
        d_ff (int): Dimensionality of the feed-forward inner layer (section 3.3).
        rope_theta (float): The RoPE Theta parameter.
        weights (dict[str, Tensor]):
            State dict of our reference implementation. {num_layers} refers to an
            integer between `0` and `num_layers - 1` (the layer index).
            The keys of this dictionary are:
            - `token_embeddings.weight`
                Token embedding matrix. Shape is (vocab_size, d_model).
            - `layers.{num_layers}.attn.q_proj.weight`
                The query projections for all `num_heads` attention heads.
                Shape is (num_heads * (d_model / num_heads), d_model).
                The rows are ordered by matrices of shape (num_heads, d_k),
                so `attn.q_proj.weight == torch.cat([q_heads.0.weight, ..., q_heads.N.weight], dim=0)`.
            - `layers.{num_layers}.attn.k_proj.weight`
                The key projections for all `num_heads` attention heads.
                Shape is (num_heads * (d_model / num_heads), d_model).
                The rows are ordered by matrices of shape (num_heads, d_k),
                so `attn.k_proj.weight == torch.cat([k_heads.0.weight, ..., k_heads.N.weight], dim=0)`.
            - `layers.{num_layers}.attn.v_proj.weight`
                The value projections for all `num_heads` attention heads.
                Shape is (num_heads * (d_model / num_heads), d_model).
                The rows are ordered by matrices of shape (num_heads, d_v),
                so `attn.v_proj.weight == torch.cat([v_heads.0.weight, ..., v_heads.N.weight], dim=0)`.
            - `layers.{num_layers}.attn.output_proj.weight`
                Weight of the multi-head self-attention output projection
                Shape is ((d_model / num_heads) * num_heads, d_model).
            - `layers.{num_layers}.ln1.weight`
                Weights of affine transform for the first RMSNorm
                applied in the transformer block.
                Shape is (d_model,).
            - `layers.{num_layers}.ffn.w1.weight`
                Weight of the first linear transformation in the FFN.
                Shape is (d_model, d_ff).
            - `layers.{num_layers}.ffn.w2.weight`
                Weight of the second linear transformation in the FFN.
                Shape is (d_ff, d_model).
            - `layers.{num_layers}.ffn.w3.weight`
                Weight of the third linear transformation in the FFN.
                Shape is (d_model, d_ff).
            - `layers.{num_layers}.ln2.weight`
                Weights of affine transform for the second RMSNorm
                applied in the transformer block.
                Shape is (d_model,).
            - `ln_final.weight`
                Weights of affine transform for RMSNorm applied to the output of the final transformer block.
                Shape is (d_model, ).
            - `lm_head.weight`
                Weights of the language model output embedding.
                Shape is (vocab_size, d_model).
        in_indices (Int[Tensor, "batch_size sequence_length"]) Tensor with input indices to run the language model on. Shape is (batch_size, sequence_length), where
            `sequence_length` is at most `context_length`.

    Returns:
        Float[Tensor, "batch_size sequence_length vocab_size"]: Tensor with the predicted unnormalized
        next-word distribution for each token.
    """
    x = run_embedding(vocab_size, d_model, weights['token_embeddings.weight'], in_indices)
    for i in range(num_layers):
        layer_weights = {
            'attn.q_proj.weight': weights[f'layers.{i}.attn.q_proj.weight'],
            'attn.k_proj.weight': weights[f'layers.{i}.attn.k_proj.weight'],
            'attn.v_proj.weight': weights[f'layers.{i}.attn.v_proj.weight'],
            'attn.output_proj.weight': weights[f'layers.{i}.attn.output_proj.weight'],
            'ln1.weight': weights[f'layers.{i}.ln1.weight'],
            'ffn.w1.weight': weights[f'layers.{i}.ffn.w1.weight'],
            'ffn.w2.weight': weights[f'layers.{i}.ffn.w2.weight'],
            'ffn.w3.weight': weights[f'layers.{i}.ffn.w3.weight'],
            'ln2.weight': weights[f'layers.{i}.ln2.weight']
        }
        x = run_transformer_block(
            d_model, num_heads, d_ff, context_length, rope_theta,
            layer_weights, x
        )
    x = run_rmsnorm(d_model, 1e-5, weights['ln_final.weight'], x)
    logits = torch.matmul(x, weights['lm_head.weight'].T)
    return logits
    #raise NotImplementedError


def run_rmsnorm(
    d_model: int,
    eps: float,
    weights: Float[Tensor, " d_model"],
    in_features: Float[Tensor, " ... d_model"],
) -> Float[Tensor, " ... d_model"]:
    """Given the weights of a RMSNorm affine transform,
    return the output of running RMSNorm on the input features.

    Args:
        d_model (int): The dimensionality of the RMSNorm input.
        eps: (float): A value added to the denominator for numerical stability.
        weights (Float[Tensor, "d_model"]): RMSNorm weights.
        in_features (Float[Tensor, "... d_model"]): Input features to run RMSNorm on. Can have arbitrary leading
            dimensions.

    Returns:
        Float[Tensor,"... d_model"]: Tensor of with the same shape as `in_features` with the output of running
        RMSNorm of the `in_features`.
    """
    rms = torch.sqrt(torch.mean(in_features ** 2, dim=-1, keepdim=True) + eps)
    normalized = in_features / rms
    return normalized * weights
    #raise NotImplementedError


def run_silu(in_features: Float[Tensor, " ..."]) -> Float[Tensor, " ..."]:
    """Given a tensor of inputs, return the output of applying SiLU
    to each element.

    Args:
        in_features(Float[Tensor, "..."]): Input features to run SiLU on. Shape is arbitrary.

    Returns:
        Float[Tensor,"..."]: of with the same shape as `in_features` with the output of applying
        SiLU to each element.
    """
    return in_features * torch.sigmoid(in_features)
    #raise NotImplementedError


def run_get_batch(
    dataset: npt.NDArray, batch_size: int, context_length: int, device: str
) -> tuple[torch.Tensor, torch.Tensor]:
    """
    Given a dataset (a 1D numpy array of integers) and a desired batch size and
    context length, sample language modeling input sequences and their corresponding
    labels from the dataset.

    Args:
        dataset (np.array): 1D numpy array of integer token IDs in the dataset.
        batch_size (int): Desired batch size to sample.
        context_length (int): Desired context length of each sampled example.
        device (str): PyTorch device string (e.g., 'cpu' or 'cuda:0') indicating the device
            to place the sampled input sequences and labels on.

    Returns:
        Tuple of torch.LongTensors of shape (batch_size, context_length). The first tuple item
        is the sampled input sequences, and the second tuple item is the corresponding
        language modeling labels.
    """
    data = torch.from_numpy(dataset).long()
    start_indices = torch.randint(0, len(data) - context_length, (batch_size,))
    inputs = torch.stack([data[i:i+context_length] for i in start_indices])
    labels = torch.stack([data[i+1:i+context_length+1] for i in start_indices])
    return inputs.to(device), labels.to(device)
    #raise NotImplementedError


def run_softmax(in_features: Float[Tensor, " ..."], dim: int) -> Float[Tensor, " ..."]:
    """
    Given a tensor of inputs, return the output of softmaxing the given `dim`
    of the input.

    Args:
        in_features (Float[Tensor, "..."]): Input features to softmax. Shape is arbitrary.
        dim (int): Dimension of the `in_features` to apply softmax to.

    Returns:
        Float[Tensor, "..."]: Tensor of with the same shape as `in_features` with the output of
        softmax normalizing the specified `dim`.
    """
    max_vals = in_features.max(dim=dim, keepdim=True).values
    shifted = in_features - max_vals
    exp_vals = torch.exp(shifted)
    sum_exp = exp_vals.sum(dim=dim, keepdim=True)
    softmax_output = exp_vals / sum_exp
    return softmax_output
    #raise NotImplementedError


def run_cross_entropy(
    inputs: Float[Tensor, " batch_size vocab_size"], targets: Int[Tensor, " batch_size"]
) -> Float[Tensor, ""]:
    """Given a tensor of inputs and targets, compute the average cross-entropy
    loss across examples.

    Args:
        inputs (Float[Tensor, "batch_size vocab_size"]): inputs[i][j] is the
            unnormalized logit of jth class for the ith example.
        targets (Int[Tensor, "batch_size"]): Tensor of shape (batch_size,) with the index of the correct class.
            Each value must be between 0 and `num_classes - 1`.

    Returns:
        Float[Tensor, ""]: The average cross-entropy loss across examples.
    """
    batch_size = inputs.shape[0]
    max_vals = inputs.max(dim=1, keepdim=True).values
    shifted = inputs - max_vals
    exp_vals = torch.exp(shifted)
    sum_exp = exp_vals.sum(dim=1, keepdim=True)
    log_softmax = shifted - torch.log(sum_exp)
    correct_log_probs = log_softmax[torch.arange(batch_size), targets]
    losses = -correct_log_probs
    return losses.mean()
    #raise NotImplementedError


def run_gradient_clipping(parameters: Iterable[torch.nn.Parameter], max_l2_norm: float) -> None:
    """Given a set of parameters, clip their combined gradients to have l2 norm at most max_l2_norm.

    Args:
        parameters (Iterable[torch.nn.Parameter]): collection of trainable parameters.
        max_l2_norm (float): a positive value containing the maximum l2-norm.

    The gradients of the parameters (parameter.grad) should be modified in-place.
    """
    total_norm = 0.0
    for p in parameters:
        if p.grad is not None:
            total_norm += p.grad.data.norm(2).item() ** 2
    total_norm = total_norm ** 0.5
    if total_norm > max_l2_norm:
        clip_coef = max_l2_norm / (total_norm + 1e-6)
        for p in parameters:
            if p.grad is not None:
                p.grad.data.mul_(clip_coef)
    #raise NotImplementedError


def get_adamw_cls() -> Any:
    """
    Returns a torch.optim.Optimizer that implements AdamW.
    """
    return torch.optim.AdamW
    #raise NotImplementedError


def run_get_lr_cosine_schedule(
    it: int,
    max_learning_rate: float,
    min_learning_rate: float,
    warmup_iters: int,
    cosine_cycle_iters: int,
):
    """
    Given the parameters of a cosine learning rate decay schedule (with linear
    warmup) and an iteration number, return the learning rate at the given
    iteration under the specified schedule.

    Args:
        it (int): Iteration number to get learning rate for.
        max_learning_rate (float): alpha_max, the maximum learning rate for
            cosine learning rate schedule (with warmup).
        min_learning_rate (float): alpha_min, the minimum / final learning rate for
            the cosine learning rate schedule (with warmup).
        warmup_iters (int): T_w, the number of iterations to linearly warm-up
            the learning rate.
        cosine_cycle_iters (int): T_c, the number of cosine annealing iterations.

    Returns:
        Learning rate at the given iteration under the specified schedule.
    """
    import math
    if it < warmup_iters:
        return max_learning_rate * (it / warmup_iters)
    elif it <= cosine_cycle_iters:
        progress = (it - warmup_iters) / (cosine_cycle_iters - warmup_iters)
        cosine_decay = 0.5 * (1 + math.cos(math.pi * progress))
        return min_learning_rate + (max_learning_rate - min_learning_rate) * cosine_decay
    else:
        return min_learning_rate
    #raise NotImplementedError


def run_save_checkpoint(
    model: torch.nn.Module,
    optimizer: torch.optim.Optimizer,
    iteration: int,
    out: str | os.PathLike | BinaryIO | IO[bytes],
):
    """
    Given a model, optimizer, and an iteration number, serialize them to disk.

    Args:
        model (torch.nn.Module): Serialize the state of this model.
        optimizer (torch.optim.Optimizer): Serialize the state of this optimizer.
        iteration (int): Serialize this value, which represents the number of training iterations
            we've completed.
        out (str | os.PathLike | BinaryIO | IO[bytes]): Path or file-like object to serialize the model, optimizer, and iteration to.
    """
    checkpoint = {
        'model_state_dict': model.state_dict(),
        'optimizer_state_dict': optimizer.state_dict(),
        'iteration': iteration
    }
    if isinstance(out, (str, os.PathLike)):
        torch.save(checkpoint, out)
    else:
        torch.save(checkpoint, out)
    #raise NotImplementedError


def run_load_checkpoint(
    src: str | os.PathLike | BinaryIO | IO[bytes],
    model: torch.nn.Module,
    optimizer: torch.optim.Optimizer,
) -> int:
    """
    Given a serialized checkpoint (path or file-like object), restore the
    serialized state to the given model and optimizer.
    Return the number of iterations that we previously serialized in
    the checkpoint.

    Args:
        src (str | os.PathLike | BinaryIO | IO[bytes]): Path or file-like object to serialized checkpoint.
        model (torch.nn.Module): Restore the state of this model.
        optimizer (torch.optim.Optimizer): Restore the state of this optimizer.
    Returns:
        int: the previously-serialized number of iterations.
    """
    if isinstance(src, (str, os.PathLike)):
        checkpoint = torch.load(src)
    else:
        checkpoint = torch.load(src)
    model.load_state_dict(checkpoint['model_state_dict'])
    optimizer.load_state_dict(checkpoint['optimizer_state_dict'])
    return checkpoint['iteration']
    #raise NotImplementedError

class BPETokenizer:
    def __init__(self, vocab: dict[int, bytes], merges: list[tuple[bytes, bytes]], special_tokens: list[str] | None = None):
        self.vocab = vocab.copy()
        self.merges = merges
        self.special_tokens = special_tokens or []
        self.vocab_inv = {v: k for k, v in self.vocab.items()}
        self.special_tokens_bytes = [token.encode('utf-8') for token in self.special_tokens]
        for special_token in self.special_tokens_bytes:
            if special_token not in self.vocab_inv:
                new_id = len(self.vocab)
                self.vocab[new_id] = special_token
                self.vocab_inv[special_token] = new_id
        self.merge_priority = {}
        for i, (a, b) in enumerate(merges):
            self.merge_priority[(a, b)] = i
        self.special_trie = self._build_special_trie()
        pattern = r"""'s|'t|'re|'ve|'m|'ll|'d| ?[\p{L}]+| ?[\p{N}]+| ?[^\s\p{L}\p{N}]+|\s+(?!\S)|\s+"""
        self.pat = re_module.compile(pattern)

    def _build_special_trie(self):
        trie = {}
        for token_bytes in self.special_tokens_bytes:
            node = trie
            for byte in token_bytes:
                if byte not in node:
                    node[byte] = {}
                node = node[byte]
            node[None] = token_bytes
        return trie

    def _find_special_tokens(self, text_bytes: bytes):
        positions = []
        i = 0
        while i < len(text_bytes):
            node = self.special_trie
            j = i
            matched_token = None
            while j < len(text_bytes) and text_bytes[j] in node:
                node = node[text_bytes[j]]
                j += 1
                if None in node:
                    matched_token = node[None]
            if matched_token:
                positions.append((i, j, matched_token))
                i = j
            else:
                i += 1
        return positions

    def encode(self, text: str) -> list[int]:
        if not text:
            return []
        text_bytes = text.encode('utf-8')
        special_positions = self._find_special_tokens(text_bytes)
        tokens = []
        last_pos = 0
        for start, end, special_token in special_positions:
            if start > last_pos:
                ordinary_bytes = text_bytes[last_pos:start]
                ordinary_str = ordinary_bytes.decode('utf-8', errors='replace')
                for match in self.pat.finditer(ordinary_str):
                    chunk = match.group(0)
                    chunk_bytes = chunk.encode('utf-8')
                    sub_ids = self._bpe_encode(chunk_bytes)
                    tokens.extend(sub_ids)
            tokens.append(self.vocab_inv[special_token])
            last_pos = end
        if last_pos < len(text_bytes):
            ordinary_bytes = text_bytes[last_pos:]
            ordinary_str = ordinary_bytes.decode('utf-8', errors='replace')
            for match in self.pat.finditer(ordinary_str):
                chunk = match.group(0)
                chunk_bytes = chunk.encode('utf-8')
                sub_ids = self._bpe_encode(chunk_bytes)
                tokens.extend(sub_ids)
        return tokens

    def _bpe_encode(self, text_bytes: bytes) -> list[int]:
        if not text_bytes:
            return []
        tokens = [bytes([b]) for b in text_bytes]
        while len(tokens) > 1:
            best_pair = None
            best_priority = float('inf')
            for i in range(len(tokens) - 1):
                pair = (tokens[i], tokens[i + 1])
                if pair in self.merge_priority:
                    priority = self.merge_priority[pair]
                    if priority < best_priority:
                        best_priority = priority
                        best_pair = pair
            if best_pair is None:
                break
            a, b = best_pair
            merged = a + b
            new_tokens = []
            i = 0
            while i < len(tokens):
                if i + 1 < len(tokens) and tokens[i] == a and tokens[i + 1] == b:
                    new_tokens.append(merged)
                    i += 2
                else:
                    new_tokens.append(tokens[i])
                    i += 1
            tokens = new_tokens
        token_ids = []
        for token in tokens:
            if token in self.vocab_inv:
                token_ids.append(self.vocab_inv[token])
            else:
                for byte in token:
                    byte_token = bytes([byte])
                    token_ids.append(self.vocab_inv[byte_token])
        return token_ids

    def decode(self, token_ids: list[int]) -> str:
        if not token_ids:
            return ""
        bytes_list = []
        for token_id in token_ids:
            if token_id in self.vocab:
                bytes_list.append(self.vocab[token_id])
            else:
                bytes_list.append(b'')
        combined_bytes = b''.join(bytes_list)
        return combined_bytes.decode('utf-8', errors='replace')

    def encode_iterable(self, iterable) -> Iterator[int]:
        for line in iterable:
            yield from self.encode(line)

def get_tokenizer(
    vocab: dict[int, bytes],
    merges: list[tuple[bytes, bytes]],
    special_tokens: list[str] | None = None,
) -> Any:
    """Given a vocabulary, a list of merges, and a list of special tokens,
    return a BPE tokenizer that uses the provided vocab, merges, and special tokens.

    Args:
        vocab (dict[int, bytes]): The tokenizer vocabulary, a mapping from int (token ID in the vocabulary)
            to bytes (token bytes)
        merges (list[tuple[bytes, bytes]]): BPE merges. Each list item is a tuple of bytes (<token1>, <token2>),
            representing that <token1> was merged with <token2>.
            Merges are ordered by order of creation.
        special_tokens (list[str] | None): A list of string special tokens for the tokenizer. These strings will never
            be split into multiple tokens, and will always be kept as a single token.

    Returns:
        A BPE tokenizer that uses the provided vocab, merges, and special tokens.
    """
    return BPETokenizer(vocab, merges, special_tokens)
    #raise NotImplementedError


def run_train_bpe(
    input_path: str | os.PathLike,
    vocab_size: int,
    special_tokens: list[str],
    **kwargs,
) -> tuple[dict[int, bytes], list[tuple[bytes, bytes]]]:
    """Given the path to an input corpus, run train a BPE tokenizer and
    output its vocabulary and merges.

    Args:
        input_path (str | os.PathLike): Path to BPE tokenizer training data.
        vocab_size (int): Total number of items in the tokenizer's vocabulary (including special tokens).
        special_tokens (list[str]): A list of string special tokens to be added to the tokenizer vocabulary.
            These strings will never be split into multiple tokens, and will always be
            kept as a single token. If these special tokens occur in the `input_path`,
            they are treated as any other string.

    Returns:
        tuple[dict[int, bytes], list[tuple[bytes, bytes]]]:
            vocab:
                The trained tokenizer vocabulary, a mapping from int (token ID in the vocabulary)
                to bytes (token bytes)
            merges:
                BPE merges. Each list item is a tuple of bytes (<token1>, <token2>),
                representing that <token1> was merged with <token2>.
                Merges are ordered by order of creation.
    """
    # Step 1: Initialize Vocabulary
    vocab: Dict[int, bytes] = {i: bytes([i]) for i in range(256)}
    next_id = 256
    special_token_bytes = [token.encode("utf-8") for token in special_tokens]
    for token_bytes in special_token_bytes:
        if token_bytes not in vocab.values():
            vocab[next_id] = token_bytes
            next_id += 1
    # Step 2: Pre-tokenization with optimizations
    pre_tokens_cnt = defaultdict(int)
    def to_bytes_list(word: str) -> list[bytes]:
        """Optimized: return list instead of tuple for faster manipulation"""
        return [bytes([b]) for b in word.encode("utf-8")]
    with open(input_path, "r", encoding="utf-8") as f:
        text = f.read()
    # Use a more efficient approach for splitting
    if special_tokens:
        # Compile regex once for efficiency
        special_pattern = re.compile("|".join(map(re.escape, special_tokens)))
        chunks = special_pattern.split(text)
    else:
        chunks = [text]
    # Pre-compile the main pattern
    main_pattern = re.compile(PAT)
    for chunk in chunks:
        if not chunk:  # Skip empty chunks
            continue
        # Use finditer for memory efficiency
        for m in main_pattern.finditer(chunk):
            word = m.group(0)
            # Use tuple of bytes for counting (hashable)
            pre_tokens_cnt[tuple(to_bytes_list(word))] += 1
    # Step 3: Compute BPE Merges with optimizations
    merges = []
    # Calculate needed merges
    initial_vocab_size = len(vocab)
    total_merges_needed = min(vocab_size - initial_vocab_size, len(pre_tokens_cnt) * 10)  # Upper bound
    # Create progress bar (optional, can remove if still too slow)
    from tqdm import tqdm
    pbar = tqdm(total=total_merges_needed, desc="Training BPE", unit="merge")
    use_tqdm = True
    # Pre-allocate data structures for efficiency
    pair_cache = {}
    while len(vocab) < vocab_size:
        pair_counts = defaultdict(int)
        # Optimized pair counting
        for token, cnt in pre_tokens_cnt.items():
            if len(token) <= 1:
                continue
            # Use cache for frequent tokens
            token_key = token
            if token_key in pair_cache:
                pairs = pair_cache[token_key]
            else:
                pairs = [(token[i], token[i+1]) for i in range(len(token)-1)]
                pair_cache[token_key] = pairs
            for pair in pairs:
                pair_counts[pair] += cnt
        if not pair_counts:
            break  # No more pairs to merge
        # Find the most frequent pair - optimized
        best_pair = max(pair_counts.items(), key=lambda x: (x[1], x[0]))[0]
        a, b = best_pair
        # Create new token
        new_token = a + b
        vocab[next_id] = new_token
        next_id += 1
        # Apply the merge with optimizations
        changes = []
        tokens_to_remove = []
        for token, cnt in pre_tokens_cnt.items():
            if len(token) <= 1:
                continue
            # Fast check if the pair might be in this token
            if a not in token or b not in token:
                continue
            # Find occurrences more efficiently
            indices = []
            i = 0
            while i < len(token) - 1:
                if token[i] == a and token[i+1] == b:
                    indices.append(i)
                    i += 1  # Skip next element since we found a pair
                i += 1
            if indices:
                # Build new token efficiently
                new_pre_token = []
                i = 0
                while i < len(token):
                    if i in indices:
                        new_pre_token.append(new_token)
                        i += 2
                    else:
                        new_pre_token.append(token[i])
                        i += 1
                new_pre_token_tuple = tuple(new_pre_token)
                changes.append((token, new_pre_token_tuple, cnt))
                tokens_to_remove.append(token)
                # Update cache for the new token
                if len(new_pre_token_tuple) > 1:
                    new_pairs = [(new_pre_token_tuple[i], new_pre_token_tuple[i+1]) 
                               for i in range(len(new_pre_token_tuple)-1)]
                    pair_cache[new_pre_token_tuple] = new_pairs
        # Apply changes efficiently
        for old_token, new_pre_token, cnt in changes:
            pre_tokens_cnt[new_pre_token] = pre_tokens_cnt.get(new_pre_token, 0) + cnt
        # Remove old tokens in batch
        for old_token in tokens_to_remove:
            if old_token in pre_tokens_cnt:
                del pre_tokens_cnt[old_token]
                if old_token in pair_cache:
                    del pair_cache[old_token]
        # Record the merge
        merges.append((a, b))
        # Update progress
        if use_tqdm:
            pbar.update(1)
            pbar.set_postfix({
                "vocab_size": len(vocab),
                "merges": len(merges),
                "tokens": len(pre_tokens_cnt)
            })
    if use_tqdm:
        pbar.close()
    return vocab, merges
    #raise NotImplementedError