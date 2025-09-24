import matplotlib.pyplot as plt
import numpy as np

# 数据
categories = ['Category 1', 'Category 2', 'Category 3', 'Category 4', 'Category 5']
values1 = np.random.rand(len(categories)) * 5  # 第一个数据集
values2 = np.random.rand(len(categories)) * 5  # 第二个数据集

# 颜色设置
colors = ['#9AFF99', '#99CCFF', '#FFCC99', '#FF9999']

# 图表设置
fig, ax1 = plt.subplots(figsize=(10, 6))

# 绘制第一个数据集的柱状图
bars1 = ax1.bar(categories, values1, color=colors[0], alpha=0.8, label='Dataset 1')

# 添加第一个数据集的折线图
ax2 = ax1.twinx()  # 创建第二个y轴，用于绘制折线图
ax2.plot(categories, np.random.rand(len(categories)) * 10, color=colors[1], marker='o', linestyle='-', linewidth=2, label='Line Plot 1')

# 调整显示
ax1.set_xlabel('Categories')
ax1.set_ylabel('Value (Bars)')
ax2.set_ylabel('Value (Line)')

# 添加图例
bars = bars1
labels = [bar.get_label() for bar in bars]
ax1.legend(bars, labels, loc='upper left')
ax2.legend(loc='upper right')

plt.tight_layout()
plt.show()

# 图表设置
fig, ax1 = plt.subplots(figsize=(10, 6))

# 绘制第二个数据集的柱状图
bars2 = ax1.bar(categories, values2, color=colors[2], alpha=0.8, label='Dataset 2')

# 添加第二个数据集的折线图
ax2 = ax1.twinx()  # 创建第二个y轴，用于绘制折线图
ax2.plot(categories, np.random.rand(len(categories)) * 10, color=colors[3], marker='o', linestyle='-', linewidth=2, label='Line Plot 2')

# 调整显示
ax1.set_xlabel('Categories')
ax1.set_ylabel('Value (Bars)')
ax2.set_ylabel('Value (Line)')

# 添加图例
bars = bars2
labels = [bar.get_label() for bar in bars]
ax1.legend(bars, labels, loc='upper left')
ax2.legend(loc='upper right')

plt.tight_layout()
plt.show()
