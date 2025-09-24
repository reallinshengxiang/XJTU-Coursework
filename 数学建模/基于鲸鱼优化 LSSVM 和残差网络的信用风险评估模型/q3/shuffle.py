import pandas as pd

# 读取文件并打乱行顺序
df = pd.read_csv('data/Ger2.csv')
df_shuffled = df.sample(frac=1).reset_index(drop=True)  # frac=1表示全部抽样，reset_index重置索引

# 将打乱后的数据存回原始文件
df_shuffled.to_csv('data/Ger2_shuffled.csv', index=False)  # index=False表示不保存索引
