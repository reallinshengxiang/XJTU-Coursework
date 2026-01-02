# Transformer和LSTM算法实现
环境配置
```
conda create -n DM python=3.13
conda activate DM
pip install -r requirements.txt
```
数据集下载
```
mkdir -p data
cd data
wget https://huggingface.co/datasets/roneneldan/TinyStories/resolve/main/TinyStoriesV2-GPT4-train.txt
wget https://huggingface.co/datasets/roneneldan/TinyStories/resolve/main/TinyStoriesV2-GPT4-valid.txt
```
测试
批量测试
```
pytest
```
单个测试
```
pytest <python_file_path>
```
Train the tokenizer.
```
python scripts/train_bpe.py
```
Use the trained tokenizer to encode the original training data in `txt` format into integer ids and save it as a one-dimensional array in dat format for easy access during training
```
python scripts/tokenize_data.py
```
Train the Transformer model.
```
python transformer_scripts/train.py
```
Test the model's ability to generate stories. 
```
python transformer_scripts/generate.py
```

Train the LSTM model.
```
python lstm_scripts/train.py
```
Test the model's ability to generate stories. 
```
python lstm_scripts/generate.py
```