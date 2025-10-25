import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import CubicSpline

# 定义常数
ccheck3 = 3
cexchange = 6
p3 = 0.1
n = 1
value = 56
break_cost = 5

# 初始化 z
z = np.zeros((101, 101))

# 计算 prob1
for i in range(101):
    for j in range(101):
        prob1 = ((1 - i / 100) * (1 - j / 100) * (1 - p3)) * value * n - 6 * n - min(n * ccheck3, (1 - (1 - i / 100) * (1 - j / 100) * p3) * n * cexchange) - break_cost * n
        z[i, j] = prob1

# 创建网格
i_vals, j_vals = np.meshgrid(np.arange(101), np.arange(101))

# 寻找 prob1 与 z = 0 平面的交线
intersection_indices = np.where(np.isclose(z, 0, atol=1e-1))

# 检查交点数量
if len(intersection_indices[0]) < 2:
    raise ValueError("Not enough intersection points found to perform cubic spline fitting.")

# 获取交点的 i, j 坐标和 z 值
i_points = i_vals[intersection_indices]
j_points = j_vals[intersection_indices]
z_points = z[intersection_indices]

# 对 i_points 和 j_points 进行排序，以确保 i_points 是递增的
sorted_indices = np.argsort(i_points)
i_points_sorted = i_points[sorted_indices]
j_points_sorted = j_points[sorted_indices]

# 删除 i_points_sorted 中重复的元素及其对应的 j_points_sorted
i_points_unique, unique_indices = np.unique(i_points_sorted, return_index=True)
j_points_unique = j_points_sorted[unique_indices]

# ---- 三次样条拟合 ----
cubic_spline = CubicSpline(i_points_unique, j_points_unique)

# 创建 i 的细化区间用于绘制拟合曲线
i_fine = np.linspace(min(i_points_sorted), max(i_points_sorted), 500)
j_fine = cubic_spline(i_fine)

# ---- 绘制图像 ----
plt.figure(figsize=(10, 6))

# 绘制交点（红色圆圈）和三次样条拟合曲线（蓝色）
plt.scatter(i_points_sorted, j_points_sorted, color='red', s=80, edgecolor='black', zorder=5)
plt.plot(i_fine, j_fine, color='blue', linewidth=2, zorder=3)

# 增加标题和标签
plt.title('relationship between p1 and p2 in the case of bound', fontsize=16, fontweight='bold')
plt.xlabel('i (p1)', fontsize=14)
plt.ylabel('j (p2)', fontsize=14)

# 美化网格
plt.grid(True, linestyle='--', alpha=0.6)

# 设置图例和显示
plt.legend(fontsize=12)
plt.tight_layout()
plt.show()

# 输出拟合曲线的表达式
print("Cubic spline fitting done.")
