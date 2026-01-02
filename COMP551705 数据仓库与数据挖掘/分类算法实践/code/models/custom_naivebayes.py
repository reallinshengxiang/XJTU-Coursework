import numpy as np
from collections import defaultdict
import warnings
warnings.filterwarnings('ignore')

class CustomNaiveBayes:
    """
    自定义朴素贝叶斯算法实现
    支持高斯朴素贝叶斯和多项式朴素贝叶斯
    """
    
    def __init__(self, priors=None, var_smoothing=1e-9, 
                 distribution='gaussian', alpha=1.0, 
                 fit_prior=True, random_state=None):
        """
        初始化自定义朴素贝叶斯
        
        参数:
        - priors: 先验概率，如果为None则从数据中学习
        - var_smoothing: 方差平滑参数，防止除零
        - distribution: 特征分布假设 ('gaussian' 或 'multinomial')
        - alpha: 拉普拉斯平滑参数（用于多项式分布）
        - fit_prior: 是否学习先验概率（用于多项式分布）
        - random_state: 随机种子
        """
        self.priors = priors
        self.var_smoothing = var_smoothing
        self.distribution = distribution
        self.alpha = alpha
        self.fit_prior = fit_prior
        self.random_state = random_state
        self.classes_ = None
        self.class_prior_ = None
        self.class_count_ = None
        self.theta_ = None  # 均值（高斯）或概率（多项式）
        self.sigma_ = None  # 方差（仅高斯分布）
        self.feature_count_ = None  # 特征计数（多项式分布）
        self.class_log_prior_ = None  # 类先验的对数
        self.feature_log_prob_ = None  # 特征概率的对数
        if random_state is not None:
            np.random.seed(random_state)
    
    def _check_params(self):
        """检查参数有效性"""
        if self.distribution not in ['gaussian', 'multinomial']:
            raise ValueError("distribution must be 'gaussian' or 'multinomial'")
        if self.var_smoothing < 0:
            raise ValueError("var_smoothing must be non-negative")
        if self.alpha < 0:
            raise ValueError("alpha must be non-negative")
    
    def _gaussian_pdf(self, x, mean, var):
        """计算高斯概率密度函数"""
        var = np.maximum(var, self.var_smoothing)
        exponent = np.exp(-((x - mean) ** 2) / (2 * var))
        return (1 / np.sqrt(2 * np.pi * var)) * exponent
    
    def _compute_gaussian_parameters(self, X, y):
        """计算高斯分布的参数（均值和方差）"""
        n_classes = len(self.classes_)
        n_features = X.shape[1]
        self.theta_ = np.zeros((n_classes, n_features))
        self.sigma_ = np.zeros((n_classes, n_features))
        for i, c in enumerate(self.classes_):
            X_c = X[y == c]
            self.theta_[i, :] = X_c.mean(axis=0)
            self.sigma_[i, :] = X_c.var(axis=0)
            self.sigma_[i, :] = np.maximum(self.sigma_[i, :], self.var_smoothing)
    
    def _compute_multinomial_parameters(self, X, y):
        """计算多项式分布的参数"""
        n_classes = len(self.classes_)
        n_features = X.shape[1]
        self.feature_count_ = np.zeros((n_classes, n_features))
        for i, c in enumerate(self.classes_):
            X_c = X[y == c]
            self.feature_count_[i, :] = X_c.sum(axis=0)
        if self.fit_prior:
            self.class_log_prior_ = np.log(self.class_prior_)
        else:
            self.class_log_prior_ = np.zeros(n_classes) - np.log(n_classes)
        feature_count_total = self.feature_count_.sum(axis=1, keepdims=True)
        self.feature_log_prob_ = np.log(self.feature_count_ + self.alpha) - \
                               np.log(feature_count_total + self.alpha * n_features)
    
    def fit(self, X, y):
        """
        训练朴素贝叶斯模型
        
        参数:
        - X: 训练特征
        - y: 训练标签
        """
        X = np.asarray(X)
        y = np.asarray(y)
        self.classes_ = np.unique(y)
        n_classes = len(self.classes_)
        n_samples = X.shape[0]
        self._check_params()
        self.class_count_ = np.zeros(n_classes)
        for i, c in enumerate(self.classes_):
            self.class_count_[i] = np.sum(y == c)
        if self.priors is not None:
            self.class_prior_ = np.asarray(self.priors)
        else:
            self.class_prior_ = self.class_count_ / n_samples
        if self.distribution == 'gaussian':
            self._compute_gaussian_parameters(X, y)
        else:
            if np.any(X < 0):
                raise ValueError("Multinomial Naive Bayes requires non-negative feature values")
            self._compute_multinomial_parameters(X, y)
        return self
    
    def _joint_log_likelihood_gaussian(self, X):
        """计算高斯分布下的联合对数似然"""
        n_samples, n_features = X.shape
        n_classes = len(self.classes_)
        joint_log_likelihood = np.zeros((n_samples, n_classes))
        for i in range(n_classes):
            joint_log_likelihood[:, i] = np.log(self.class_prior_[i])
            for j in range(n_features):
                log_prob = np.log(self._gaussian_pdf(X[:, j], self.theta_[i, j], self.sigma_[i, j]))
                joint_log_likelihood[:, i] += log_prob
        return joint_log_likelihood
    
    def _joint_log_likelihood_multinomial(self, X):
        """计算多项式分布下的联合对数似然"""
        return self.class_log_prior_ + X.dot(self.feature_log_prob_.T)
    
    def predict(self, X):
        """
        预测
        
        参数:
        - X: 测试特征
        
        返回:
        - 预测标签
        """
        return np.argmax(self.predict_proba(X), axis=1)
    
    def predict_proba(self, X):
        """
        预测概率
        
        参数:
        - X: 测试特征
        
        返回:
        - 预测概率
        """
        X = np.asarray(X)
        if self.distribution == 'gaussian':
            joint_log_likelihood = self._joint_log_likelihood_gaussian(X)
        else:
            joint_log_likelihood = self._joint_log_likelihood_multinomial(X)
        log_prob_x = np.logaddexp.reduce(joint_log_likelihood, axis=1)
        proba = np.exp(joint_log_likelihood - log_prob_x.reshape(-1, 1))
        return proba
    
    def predict_log_proba(self, X):
        """
        预测对数概率
        
        参数:
        - X: 测试特征
        
        返回:
        - 预测对数概率
        """
        X = np.asarray(X)
        if self.distribution == 'gaussian':
            joint_log_likelihood = self._joint_log_likelihood_gaussian(X)
        else:
            joint_log_likelihood = self._joint_log_likelihood_multinomial(X)
        log_prob_x = np.logaddexp.reduce(joint_log_likelihood, axis=1)
        log_proba = joint_log_likelihood - log_prob_x.reshape(-1, 1)
        return log_proba
    
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
    
    def get_params(self, deep=True):
        """获取模型参数"""
        return {
            'priors': self.priors,
            'var_smoothing': self.var_smoothing,
            'distribution': self.distribution,
            'alpha': self.alpha,
            'fit_prior': self.fit_prior,
            'random_state': self.random_state
        }
    
    def set_params(self, **parameters):
        """设置模型参数（用于网格搜索）"""
        for parameter, value in parameters.items():
            setattr(self, parameter, value)
        return self