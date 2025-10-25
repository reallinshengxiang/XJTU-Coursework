import numpy as np
from scipy.integrate import solve_ivp
import matplotlib.pyplot as plt

# 定义常数
C1 = 2
C2 = 4
N = 100000
p = 0.1
import pdb

# 定义 P(E) 函数
def P(E):
    if 1-p-E < 0:
        print(1-p-E)
        pdb.set_trace()
    return (p + E) * np.log(p + E) + (1 - p - E) * np.log(1 - p - E)

# 定义微分方程 dn/dE 的表达式
def ode(E, n):
    return (N * (E + p) * C2 + N * P(E)) / C1

# 设置 E 的取值范围
E_span = (0.01, 0.89)  # E 的起始值和终止值
n_initial = [0.1]  # n 的初始值

# 求解微分方程
sol = solve_ivp(ode, E_span, n_initial, method='RK45', t_eval=np.linspace(E_span[0], E_span[1], 100))
print(sol)
# 绘制结果，使用美化技巧
plt.figure(figsize=(10, 6))

# 设置线条的粗细、颜色、样式
plt.plot(sol.t, sol.y[0], label='n(E)', color='b', linestyle='-', linewidth=2, marker='o', markersize=5, markerfacecolor='red')

# 增加填充颜色
plt.fill_between(sol.t, sol.y[0], color='lightblue', alpha=0.3)

# 设置标签和标题
plt.xlabel('E', fontsize=14)
plt.ylabel('n', fontsize=14)

# 美化图例
plt.legend(fontsize=12, loc='best')

# 添加网格
plt.grid(True, linestyle='--', alpha=0.7)

# 显示图形
plt.tight_layout()
plt.show()
