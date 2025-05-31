import json
import torch
import torch.nn as nn
from torch.utils.data import Dataset, DataLoader
from torch.optim import AdamW
import argparse
import os
from tqdm import tqdm
from transformers import BertTokenizerFast

class Config:
    def __init__(self):
        self.batch_size = 8
        self.learning_rate = 3e-5
        self.epochs = 3
        self.max_length = 384
        self.model_dir = "./model"
        self.train_path = "train-v1.1.json"
        self.dev_path = "dev-v1.1.json"
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        self.d_model = 768
        self.nhead = 12
        self.dim_feedforward = 3072
        self.dropout = 0.1
        self.num_layers = 7

class SQuADProcessor:
    def __init__(self, config):
        self.config = config
        self.tokenizer = BertTokenizerFast.from_pretrained('bert-base-uncased')
    
    def load_data(self, path):
        with open(path, 'r') as f:
            return json.load(f)['data']
    
    def process(self, data):
        examples = []
        for article in data:
            for para in article['paragraphs']:
                context = para['context']
                for qa in para['qas']:
                    example = {
                        'context': context,
                        'question': qa['question'],
                        'answer': qa['answers'][0]
                    }
                    examples.append(example)
        return examples
    
    def create_features(self, examples):
        input_ids, masks = [], []
        start_pos, end_pos = [], []
        
        for ex in examples:
            encoding = self.tokenizer(
                ex['question'],
                ex['context'],
                max_length=self.config.max_length,
                truncation=True,
                padding='max_length',
                return_offsets_mapping=True
            )
            
            ans_start = ex['answer']['answer_start']
            ans_end = ans_start + len(ex['answer']['text'])
            
            start_char = ans_start
            end_char = ans_end
            sequence_ids = encoding.sequence_ids()
            
            # Find token positions
            start_token, end_token = -1, -1
            for i, (idx, (s, e)) in enumerate(zip(sequence_ids, encoding.offset_mapping)):
                if idx != 1: continue  # Only look at context tokens
                if s <= start_char < e: start_token = i
                if s < end_char <= e: end_token = i
            
            if start_token != -1 and end_token != -1:
                input_ids.append(encoding['input_ids'])
                masks.append(encoding['attention_mask'])
                start_pos.append(start_token)
                end_pos.append(end_token)
        
        return {
            'input_ids': torch.tensor(input_ids),
            'attention_mask': torch.tensor(masks),
            'start_pos': torch.tensor(start_pos),
            'end_pos': torch.tensor(end_pos)
        }

class SQuADDataset(Dataset):
    def __init__(self, features):
        self.features = features
    
    def __len__(self):
        return len(self.features['input_ids'])
    
    def __getitem__(self, idx):
        return {k: v[idx] for k, v in self.features.items()}

class TransformerQA(nn.Module):
    def __init__(self, config):
        super().__init__()
        self.embedding = nn.Embedding(self.tokenizer.vocab_size, config.d_model)
        self.pos_encoder = nn.Parameter(torch.zeros(config.max_length, config.d_model))
        
        encoder_layer = nn.TransformerEncoderLayer(
            d_model=config.d_model,
            nhead=config.nhead,
            dim_feedforward=config.dim_feedforward,
            dropout=config.dropout
        )
        self.encoder = nn.TransformerEncoder(encoder_layer, config.num_layers)
        self.start_fc = nn.Linear(config.d_model, 1)
        self.end_fc = nn.Linear(config.d_model, 1)
        self.dropout = nn.Dropout(config.dropout)
    
    def forward(self, input_ids, attention_mask):
        x = self.embedding(input_ids) + self.pos_encoder[:input_ids.size(1)]
        x = self.dropout(x)
        x = x.permute(1, 0, 2)  # [seq_len, bs, dim]
        
        output = self.encoder(x, src_key_padding_mask=~attention_mask.bool())
        output = output.permute(1, 0, 2)  # [bs, seq_len, dim]
        
        start_logits = self.start_fc(output).squeeze(-1)
        end_logits = self.end_fc(output).squeeze(-1)
        return start_logits, end_logits

class QATrainer:
    def __init__(self, config, model, train_loader, dev_loader=None):
        self.config = config
        self.model = model.to(config.device)
        self.train_loader = train_loader
        self.dev_loader = dev_loader
        self.optimizer = AdamW(model.parameters(), lr=config.learning_rate)
    
    def train_epoch(self):
        self.model.train()
        total_loss = 0
        for batch in tqdm(self.train_loader, desc="Training"):
            input_ids = batch['input_ids'].to(self.config.device)
            mask = batch['attention_mask'].to(self.config.device)
            start = batch['start_pos'].to(self.config.device)
            end = batch['end_pos'].to(self.config.device)
            
            self.optimizer.zero_grad()
            s_logits, e_logits = self.model(input_ids, mask)
            
            loss = nn.CrossEntropyLoss()(s_logits, start) + \
                   nn.CrossEntropyLoss()(e_logits, end)
            
            loss.backward()
            self.optimizer.step()
            total_loss += loss.item()
        return total_loss / len(self.train_loader)
    
    def evaluate(self):
        self.model.eval()
        # 请补全evaluate过程

    
    def save_model(self, path):
        torch.save(self.model.state_dict(), path)
    
    def load_model(self, path):
        self.model.load_state_dict(torch.load(path))

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--mode", choices=["train", "test"], required=True)
    parser.add_argument("--model_path", type=str)
    args = parser.parse_args()
    
    # 训练命令：python script.py --mode train 
    # 测试命令：python script.py --mode test --model_path /path/to/model
    
    config = Config()
    processor = SQuADProcessor(config)
    
    if args.mode == "train":
        # 训练流程
        train_data = processor.load_data(config.train_path)
        train_examples = processor.process(train_data)
        train_features = processor.create_features(train_examples)
        train_dataset = SQuADDataset(train_features)
        train_loader = DataLoader(train_dataset, batch_size=config.batch_size, shuffle=True)
        
        dev_data = processor.load_data(config.dev_path)
        dev_examples = processor.process(dev_data)
        dev_features = processor.create_features(dev_examples)
        dev_loader = DataLoader(SQuADDataset(dev_features), batch_size=config.batch_size)
        
        model = TransformerQA(config)
        trainer = QATrainer(config, model, train_loader, dev_loader)
        
        for epoch in range(config.epochs):
            avg_loss = trainer.train_epoch()
            print(f"Epoch {epoch+1} Loss: {avg_loss}")
            metrics = trainer.evaluate()
            print(metrics)
            trainer.save_model(f"{config.model_dir}/epoch_{epoch+1}.pt")
    
    elif args.mode == "test":
        # 测试流程
        dev_data = processor.load_data(config.dev_path)
        dev_examples = processor.process(dev_data)
        dev_features = processor.create_features(dev_examples)
        dev_loader = DataLoader(SQuADDataset(dev_features), batch_size=config.batch_size)
        
        model = TransformerQA(config)
        trainer = QATrainer(config, model, None, dev_loader)
        trainer.load_model(args.model_path)
        metrics = trainer.evaluate()
        print(f"Test Results - {metrics}")

if __name__ == "__main__":
    main()
