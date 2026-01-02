import numpy as np
from collections import Counter
from sklearn.utils import check_array
import warnings
warnings.filterwarnings('ignore')

class CustomKNN:
    """
    自定义K-最近邻算法实现（兼容scikit-learn接口）
    """
    def __init__(self, n_neighbors=5, weights='uniform', metric='euclidean', 
                 algorithm='brute', p=2, random_state=None):
        """
        初始化自定义KNN
        
        参数:
        - n_neighbors: 近邻数量
        - weights: 权重计算方式 ('uniform' 或 'distance')
        - metric: 距离度量 ('euclidean', 'manhattan', 'minkowski', 'cosine')
        - algorithm: 算法实现 ('brute' 或 'kd_tree' - 这里只实现brute)
        - p: Minkowski距离的参数
        - random_state: 随机种子（用于打破平局）
        """
        self.n_neighbors = n_neighbors
        self.weights = weights
        self.metric = metric
        self.algorithm = algorithm
        self.p = p
        self.random_state = random_state
        self.X_train = None
        self.y_train = None
        self.n_features_ = None
        self.n_classes_ = None
        self.classes_ = None
        if random_state is not None:
            np.random.seed(random_state)
    
    def _check_params(self):
        """检查参数有效性"""
        if self.n_neighbors <= 0:
            raise ValueError("n_neighbors must be positive")
        if self.weights not in ['uniform', 'distance']:
            raise ValueError("weights must be 'uniform' or 'distance'")
        if self.metric not in ['euclidean', 'manhattan', 'minkowski', 'cosine']:
            raise ValueError("metric not supported")
    
    def _calculate_distance(self, x1, x2):
        """计算两个样本之间的距离"""
        if self.metric == 'euclidean':
            return np.sqrt(np.sum((x1 - x2) **2))
        elif self.metric == 'manhattan':
            return np.sum(np.abs(x1 - x2))
        elif self.metric == 'minkowski':
            return np.sum(np.abs(x1 - x2)** self.p) **(1 / self.p)
        elif self.metric == 'cosine':
            dot_product = np.dot(x1, x2)
            norm_x1 = np.linalg.norm(x1)
            norm_x2 = np.linalg.norm(x2)
            if norm_x1 == 0 or norm_x2 == 0:
                return 1.0
            return 1 - (dot_product / (norm_x1 * norm_x2))
        else:
            return np.sqrt(np.sum((x1 - x2)** 2))
    
    def _get_neighbors(self, x):
        """获取x的k个最近邻"""
        distances = []
        for i, train_sample in enumerate(self.X_train):
            dist = self._calculate_distance(x, train_sample)
            distances.append((i, dist))
        distances.sort(key=lambda x: x[1])
        neighbors = distances[:self.n_neighbors]
        return neighbors
    
    def _predict_single(self, x):
        """预测单个样本"""
        neighbors = self._get_neighbors(x)
        neighbor_indices = [idx for idx, _ in neighbors]
        neighbor_distances = [dist for _, dist in neighbors]
        neighbor_labels = self.y_train[neighbor_indices]
        if self.weights == 'uniform':
            weights = np.ones(len(neighbor_labels))
        else:
            epsilon = 1e-8
            weights = 1.0 / (np.array(neighbor_distances) + epsilon)
        vote_counts = {}
        for label, weight in zip(neighbor_labels, weights):
            if label not in vote_counts:
                vote_counts[label] = 0
            vote_counts[label] += weight
        if vote_counts:
            max_vote = max(vote_counts.values())
            candidates = [label for label, count in vote_counts.items() if count == max_vote]
            if len(candidates) == 1:
                return candidates[0]
            else:
                return np.random.choice(candidates)
        else:
            return np.argmax(np.bincount(self.y_train))
    
    def fit(self, X, y):
        """
        训练KNN模型（只是存储数据）
        
        参数:
        - X: 训练特征
        - y: 训练标签
        """
        X = check_array(X)
        self.X_train = X
        self.y_train = np.array(y)
        self.n_features_ = X.shape[1]
        self.n_classes_ = len(np.unique(y))
        self.classes_ = np.unique(y)
        self._check_params()
        return self
    
    def predict(self, X):
        """
        预测
        
        参数:
        - X: 测试特征
        
        返回:
        - 预测标签
        """
        X = check_array(X)
        predictions = []
        for x in X:
            pred = self._predict_single(x)
            predictions.append(pred)
        return np.array(predictions)
    
    def predict_proba(self, X):
        """
        预测概率
        
        参数:
        - X: 测试特征
        
        返回:
        - 预测概率
        """
        X = check_array(X)
        n_samples = X.shape[0]
        proba = np.zeros((n_samples, self.n_classes_))
        for i, x in enumerate(X):
            neighbors = self._get_neighbors(x)
            neighbor_indices = [idx for idx, _ in neighbors]
            neighbor_distances = [dist for _, dist in neighbors]
            neighbor_labels = self.y_train[neighbor_indices]
            if self.weights == 'uniform':
                weights = np.ones(len(neighbor_labels))
            else:
                epsilon = 1e-8
                weights = 1.0 / (np.array(neighbor_distances) + epsilon)
            for label, weight in zip(neighbor_labels, weights):
                proba[i, label] += weight
            if np.sum(proba[i]) > 0:
                proba[i] /= np.sum(proba[i])
            else:
                proba[i] = np.ones(self.n_classes_) / self.n_classes_
        return proba
    
    def score(self, X, y):
        """
        计算准确率
        
        参数:
        - X: 测试特征
        - y: 真实标签
        
        返回:
        - 准确率
        """
        predictions = self.predict(X)
        return np.mean(predictions == y)
    
    def kneighbors(self, X, n_neighbors=None):
        """
        查找k个最近邻
        
        参数:
        - X: 查询点
        - n_neighbors: 邻居数量（如果不指定则使用self.n_neighbors）
        
        返回:
        - distances: 距离矩阵
        - indices: 索引矩阵
        """
        if n_neighbors is None:
            n_neighbors = self.n_neighbors
        X = check_array(X)
        n_queries = X.shape[0]
        distances = np.zeros((n_queries, n_neighbors))
        indices = np.zeros((n_queries, n_neighbors), dtype=int)
        for i, x in enumerate(X):
            all_distances = []
            for j, train_sample in enumerate(self.X_train):
                dist = self._calculate_distance(x, train_sample)
                all_distances.append((j, dist))
            all_distances.sort(key=lambda x: x[1])
            for k in range(n_neighbors):
                if k < len(all_distances):
                    indices[i, k] = all_distances[k][0]
                    distances[i, k] = all_distances[k][1]
        
        return distances, indices

    def get_params(self, deep=True):
        """获取模型参数（用于网格搜索）"""
        return {
            'n_neighbors': self.n_neighbors,
            'weights': self.weights,
            'metric': self.metric,
            'algorithm': self.algorithm,
            'p': self.p,
            'random_state': self.random_state
        }

    def set_params(self, **parameters):
        """设置模型参数（用于网格搜索）"""
        for parameter, value in parameters.items():
            setattr(self, parameter, value)
        return self