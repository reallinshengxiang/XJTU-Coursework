import numpy as np
import matplotlib.pyplot as plt

# 定义成本矩阵
cost_matrix = np.array([
    [0, 1],
    [5, 0]
])
plt.rcParams['font.sans-serif'] = ['SimHei']  # 指定默认字体
plt.rcParams['axes.unicode_minus'] = False  # 解决保存图像是负号'-'显示为方块的问题

# 定义行和列的标签
row_labels = ['1 (正常)', '2 (失信)']
col_labels = ['1 (预测正常)', '2 (预测失信)']

# 绘制热力图
plt.figure(figsize=(8, 6))
plt.imshow(cost_matrix, cmap='coolwarm', interpolation='nearest')

# 添加颜色条
plt.colorbar()

# 设置坐标轴标签
plt.xticks(np.arange(len(col_labels)), col_labels, rotation=45)
plt.yticks(np.arange(len(row_labels)), row_labels)
plt.xlabel('预测')
plt.ylabel('真实')

# 添加文本标签
for i in range(len(row_labels)):
    for j in range(len(col_labels)):
        plt.text(j, i, cost_matrix[i, j], ha='center', va='center', color='black', fontsize=14)



# 显示图像
plt.tight_layout()
plt.show()
