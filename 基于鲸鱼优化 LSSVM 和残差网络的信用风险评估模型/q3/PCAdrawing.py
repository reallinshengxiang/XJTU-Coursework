import pandas as pd
import matplotlib.pyplot as plt
from sklearn.decomposition import PCA
from sklearn.mixture import GaussianMixture
from sklearn.preprocessing import StandardScaler

filename = 'data/Ger2.csv'
data = pd.read_csv(filename)
plt.rcParams['font.sans-serif'] = ['SimHei']  # 指定默认字体
plt.rcParams['axes.unicode_minus'] = False  # 解决保存图像是负号'-'显示为方块的问题

X = data.iloc[:, :20]

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

n_components = 4
gmm = GaussianMixture(n_components=n_components)
gmm.fit(X_scaled)

cluster_labels = gmm.predict(X_scaled)

data['cluster'] = cluster_labels

pca = PCA(n_components=3)
X_pca = pca.fit_transform(X_scaled)

fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')
scatter = ax.scatter(X_pca[:, 0], X_pca[:, 1], X_pca[:, 2], c=cluster_labels, cmap='viridis', alpha=0.5)
ax.set_title('PCA可视化散点图 (3D)')
ax.set_xlabel('主成分1')
ax.set_ylabel('主成分2')
ax.set_zlabel('主成分3')
legend = ax.legend(*scatter.legend_elements(), title='Clusters')
ax.add_artist(legend)
plt.show()
