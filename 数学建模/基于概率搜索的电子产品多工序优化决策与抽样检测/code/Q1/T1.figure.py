import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as stats

# 定义均值和标准差
mu = 0       # 均值
sigma = 1    # 标准差

# 生成正态分布的 x 值
x = np.linspace(mu - 4*sigma, mu + 4*sigma, 1000)

# 生成正态分布的概率密度函数 y 值
y = stats.norm.pdf(x, mu, sigma)

# 绘制正态分布曲线
plt.plot(x, y, color='blue')

# 计算 95% 单侧置信区间 (上侧)
upper_bound = stats.norm.ppf(0.95, loc=mu, scale=sigma)
#lower_bound =stats.norm.ppf()
# 填充置信区间区域 (单侧上限)
plt.fill_between(x, y, where=(x <= upper_bound), color='lightblue', alpha=0.5)

# 标注置信区间边界
plt.axvline(upper_bound, color='red')

# 添加图例、标题和标签
#plt.title('Normal Distribution with 95% One-sided Upper Confidence Interval')
plt.xlabel('X')
plt.legend()

# 显示图形
plt.show()
