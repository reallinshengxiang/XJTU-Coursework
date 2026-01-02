import os
import sys
import json
import torch
import pathlib
import argparse
import numpy as np
from tqdm import tqdm
import matplotlib.pyplot as plt
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))
from utils import _to_device_and_compile
from model import LSTMNetwork
from tests.adapters import *

DATA_DIR = pathlib.Path(__file__).resolve().parent.parent / "data"
TRAIN_DATA_PATH = os.path.join(DATA_DIR, "train.dat")
VAL_DATA_PATH = os.path.join(DATA_DIR, "valid.dat")
CONFIG_PATH = "lstm_scripts/config.json"

class TrainingVisualizer:
    def __init__(self, save_path):
        plt.switch_backend('Agg') 
        self.save_path = save_path
        self.train_losses = []
        self.val_losses = []
        self.val_iterations = []
        self.learning_rates = []
        self.iterations = []
        self.viz_dir = os.path.join(save_path, "visualizations")
        os.makedirs(self.viz_dir, exist_ok=True)
        plt.style.use('seaborn-v0_8')
        plt.rcParams['font.family'] = 'DejaVu Sans'

    def update_training_loss(self, iteration, loss, lr):
        """Update training loss and learning rate"""
        self.train_losses.append(float(loss))
        self.learning_rates.append(float(lr))
        self.iterations.append(int(iteration))

    def update_validation_loss(self, iteration, loss):
        """Update validation loss"""
        self.val_losses.append(float(loss))
        self.val_iterations.append(int(iteration))

    def _safe_ratio_check(self, values, threshold):
        """Safely check if ratio exceeds threshold without division by zero"""
        if len(values) < 2:
            return False
        min_val = min(values)
        max_val = max(values)
        if min_val <= 0:
            return False
        return (max_val / min_val) > threshold

    def plot_training_progress(self, current_iteration):
        """Plot training progress with safe error handling"""
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(15, 10))
        # 1. Training loss curve
        if len(self.iterations) > 0:
            ax1.plot(self.iterations, self.train_losses, 'b-', alpha=0.7, label='Training Loss')
            ax1.set_xlabel('Iteration')
            ax1.set_ylabel('Training Loss')
            ax1.set_title('Training Loss Over Time')
            ax1.grid(True, alpha=0.3)
            ax1.legend()
            # Safe log scale check
            if self._safe_ratio_check(self.train_losses, 100):
                ax1.set_yscale('log')
        # 2. Validation loss curve
        if len(self.val_iterations) > 0:
            ax2.plot(self.val_iterations, self.val_losses, 'r-', marker='o', markersize=3, label='Validation Loss')
            ax2.set_xlabel('Iteration')
            ax2.set_ylabel('Validation Loss')
            ax2.set_title('Validation Loss Over Time')
            ax2.grid(True, alpha=0.3)
            ax2.legend()
        # 3. Learning rate schedule
        if len(self.learning_rates) > 0:
            ax3.plot(self.iterations, self.learning_rates, 'g-', alpha=0.7)
            ax3.set_xlabel('Iteration')
            ax3.set_ylabel('Learning Rate')
            ax3.set_title('Learning Rate Schedule')
            ax3.grid(True, alpha=0.3)
            # Safe log scale check for learning rates
            if self._safe_ratio_check(self.learning_rates, 10):
                ax3.set_yscale('log')
        # 4. Recent loss trend (last 1000 points)
        if len(self.train_losses) > 100:
            recent_iterations = self.iterations[-1000:]
            recent_losses = self.train_losses[-1000:]
            ax4.plot(recent_iterations, recent_losses, 'purple', alpha=0.8)
            ax4.set_xlabel('Iteration')
            ax4.set_ylabel('Training Loss')
            ax4.set_title('Recent Training Loss Trend (Last 1000 steps)')
            ax4.grid(True, alpha=0.3)
        plt.tight_layout()
        save_path = os.path.join(self.viz_dir, f'training_progress_iter_{current_iteration}.png')
        plt.savefig(save_path, dpi=150, bbox_inches='tight')
        print(f"Visualization saved to: {save_path}")
        plt.close()

    def save_training_data(self):
        """Save training data to file"""
        data = {
            'iterations': self.iterations,
            'train_losses': self.train_losses,
            'val_iterations': self.val_iterations,
            'val_losses': self.val_losses,
            'learning_rates': self.learning_rates
        }
        save_path = os.path.join(self.viz_dir, 'training_data.json')
        with open(save_path, 'w') as f:
            json.dump(data, f, indent=2)
        print(f"Training data saved to: {save_path}")

def get_memmap_dataset(path, dtype=np.int32):
    """Load memory-mapped dataset safely"""
    arr = np.memmap(path, dtype=dtype, mode="r")
    return arr

def get_batch(memmap_arr, batch_size, context_length):
    """Get a random batch from memory-mapped array"""
    N = len(memmap_arr)
    if N < context_length + 1:
        raise ValueError(f"Dataset too small for context length {context_length}")
    ix = np.random.randint(0, N - context_length - 1, size=(batch_size,))
    x = np.stack([memmap_arr[i:i+context_length] for i in ix])
    y = np.stack([memmap_arr[i+1:i+context_length+1] for i in ix])
    return torch.tensor(x, dtype=torch.long), torch.tensor(y, dtype=torch.long)

def memmap_val_iterator(memmap_arr, batch_size, context_length):
    """Create validation iterator over memory-mapped array"""
    N = len(memmap_arr)
    nb = (N - context_length - 1) // batch_size
    for bi in range(nb):
        base = bi * batch_size
        x = np.stack([memmap_arr[i:i+context_length] for i in range(base, base + batch_size)])
        y = np.stack([memmap_arr[i+1:i+context_length+1] for i in range(base, base + batch_size)])
        yield torch.tensor(x, dtype=torch.long), torch.tensor(y, dtype=torch.long)

class DotDict(dict):
    """dot.notation access to dictionary attributes"""
    __getattr__ = dict.get
    __setattr__ = dict.__setitem__
    __delattr__ = dict.__delitem__

def validate_config(config):
    """Validate training configuration"""
    required_keys = ['lr', 'min_lr', 'warmup_iters', 'cosine_iters', 'batch_size', 
                    'context_length', 'train_steps', 'val_interval', 'save_interval']
    for key in required_keys:
        if key not in config:
            raise ValueError(f"Missing required config key: {key}")
    if config['batch_size'] <= 0 or config['context_length'] <= 0:
        raise ValueError("Batch size and context length must be positive")
    return True

def activation_regularization_loss(state, alpha=1e-3):
    """Calculate activation regularization loss for LSTM states"""
    if state is None:
        return 0.0
    
    h_state, c_state = state
    reg_loss = 0.0
    
    # Regularize hidden state
    if h_state is not None:
        reg_loss += alpha * torch.sum(h_state ** 2)
    
    # Regularize cell state  
    if c_state is not None:
        reg_loss += alpha * torch.sum(c_state ** 2)
    
    return reg_loss

def main():
    # Load model and configuration
    if not os.path.exists(CONFIG_PATH):
        raise FileNotFoundError(f"Config file not found: {CONFIG_PATH}")
    with open(CONFIG_PATH, 'r') as f:
        config = json.load(f)
    
    # Create LSTM model instead of Transformer
    model = LSTMNetwork(**config["model"])  
    
    # Merge all config sections into single params
    params = {}
    for group in config.values():
        if isinstance(group, dict):
            params.update(group)
    args = DotDict(params)
    
    # Validate configuration
    validate_config(args)
    
    # Setup device and compile
    model, device = _to_device_and_compile(model)
    print(f"Using device: {device}")
    
    # Create save directory
    os.makedirs(args.save_path, exist_ok=True)
    
    # Initialize visualizer
    visualizer = TrainingVisualizer(args.save_path)
    
    # Load datasets
    print("Loading datasets...")
    train_data = get_memmap_dataset(TRAIN_DATA_PATH)
    val_data = get_memmap_dataset(VAL_DATA_PATH)
    print(f"Train data size: {len(train_data)}, Val data size: {len(val_data)}")
    
    # Setup optimizer
    AdamW = get_adamw_cls()
    optimizer = AdamW(model.parameters(), lr=args.lr, weight_decay=args.weight_decay)
    
    # Resume from checkpoint
    start_iter = 0
    if args.resume_checkpoint:
        print(f"Resuming from checkpoint {args.resume_checkpoint}")
        resume_ckpt_path = pathlib.Path(__file__).resolve().parent.parent / f"lstm_checkpoints/ckpt_iter{args.resume_checkpoint}.pt"
        if os.path.exists(resume_ckpt_path):
            start_iter = run_load_checkpoint(resume_ckpt_path, model, optimizer)
            print(f"Resumed at iteration {start_iter}")
        else:
            print(f"Warning: Checkpoint not found at {resume_ckpt_path}, starting from scratch")
    
    # Training loop
    print(f"Starting training from iteration {start_iter} to {args.train_steps}")
    print(f"Validation interval: every {args.val_interval} iterations")
    print(f"Save interval: every {args.save_interval} iterations")
    log_interval = max(100, args.val_interval // 10)
    
    pbar = tqdm(range(start_iter, args.train_steps), desc="Training", initial=start_iter, total=args.train_steps)
    
    for iteration in pbar:
        model.train()
        x, y = get_batch(train_data, args.batch_size, args.context_length)
        x, y = x.to(device), y.to(device)
        
        # LSTM forward pass - initialize state for each batch
        state = None
        logits, state = model(x, state)
        
        # Calculate loss with activation regularization
        ce_loss = run_cross_entropy(
            logits.reshape(-1, logits.shape[-1]),
            y.reshape(-1)
        )
        reg_loss = activation_regularization_loss(state, alpha=1e-3)
        loss = ce_loss + reg_loss
        
        # Learning rate scheduling
        lr = run_get_lr_cosine_schedule(iteration, args.lr, args.min_lr, args.warmup_iters, args.cosine_iters)
        for param_group in optimizer.param_groups:
            param_group['lr'] = lr
        
        # Optimization step
        optimizer.zero_grad()
        loss.backward()
        run_gradient_clipping(model.parameters(), args.clip_grad_norm)
        optimizer.step()
        
        # Record training loss and learning rate
        visualizer.update_training_loss(iteration, loss.item(), lr)
        pbar.set_postfix({
            'loss': f'{loss.item():.4f}',
            'ce_loss': f'{ce_loss.item():.4f}',
            'reg_loss': f'{reg_loss.item():.4f}',
            'lr': f'{lr:.2e}'
        })
        
        # Validation
        if (iteration + 1) % args.val_interval == 0:
            model.eval()
            with torch.no_grad():
                val_losses = []
                count = 0
                for x_val, y_val in memmap_val_iterator(val_data, args.batch_size, args.context_length):
                    x_val, y_val = x_val.to(device), y_val.to(device)
                    
                    # LSTM validation forward pass
                    val_state = None
                    val_logits, val_state = model(x_val, val_state)
                    val_loss = run_cross_entropy(
                        val_logits.reshape(-1, val_logits.shape[-1]),
                        y_val.reshape(-1)
                    )
                    val_losses.append(val_loss.item())
                    count += 1
                    if count >= args.val_batches:
                        break
                
                val_loss_mean = np.mean(val_losses)
                print(f"\niter {iteration}: train_loss = {loss.item():.4f}, VALID loss = {val_loss_mean:.4f}, lr = {lr:.2e}")
                
                # Record validation loss
                visualizer.update_validation_loss(iteration, val_loss_mean)
        
        elif (iteration + 1) % log_interval == 0:
            print(f"\niter {iteration}: train_loss = {loss.item():.4f}, lr = {lr:.2e}")
        
        # Save checkpoint and visualization
        if (iteration + 1) % args.save_interval == 0:
            ckpt_name = os.path.join(args.save_path, f"ckpt_iter{iteration+1}.pt")
            run_save_checkpoint(model, optimizer, iteration+1, ckpt_name)
            print(f"Checkpoint saved to {ckpt_name}")
            
            # Update visualization
            visualizer.plot_training_progress(iteration+1)
            visualizer.save_training_data()
    
    pbar.close()
    
    # Final visualization after training completion
    print("Training completed! Generating final visualization...")
    visualizer.plot_training_progress(args.train_steps)
    visualizer.save_training_data()
    print(f"Training data and visualizations saved to {visualizer.viz_dir}")

if __name__ == "__main__":
    main()