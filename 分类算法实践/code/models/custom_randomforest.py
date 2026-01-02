import numpy as np
from collections import Counter
import warnings
warnings.filterwarnings('ignore')

class TreeNode:
    """
    决策树节点类
    """
    def __init__(self, feature_index=None, threshold=None, left=None, right=None, 
                 value=None, gini=None, samples=None):
        self.feature_index = feature_index  # 分裂特征索引
        self.threshold = threshold          # 分裂阈值
        self.left = left                    # 左子树
        self.right = right                  # 右子树
        self.value = value                  # 叶节点的预测值
        self.gini = gini                    # 节点的基尼系数
        self.samples = samples              # 节点样本数量

class CustomDecisionTree:
    """
    完全自定义的决策树分类器（CART算法）
    """
    
    def __init__(self, max_depth=None, min_samples_split=2, min_samples_leaf=1,
                 max_features='sqrt', random_state=None):
        """
        初始化自定义决策树
        
        参数:
        - max_depth: 树的最大深度
        - min_samples_split: 分裂所需最小样本数
        - min_samples_leaf: 叶节点最小样本数
        - max_features: 每次分裂考虑的特征数
        - random_state: 随机种子
        """
        self.max_depth = max_depth if max_depth else float('inf')
        self.min_samples_split = min_samples_split
        self.min_samples_leaf = min_samples_leaf
        self.max_features = max_features
        self.random_state = random_state
        self.tree = None
        self.n_classes_ = None
        self.n_features_ = None
        self.classes_ = None
        if random_state is not None:
            np.random.seed(random_state)
    
    def _gini_impurity(self, y):
        """计算基尼不纯度"""
        if len(y) == 0:
            return 0
        class_counts = np.bincount(y)
        class_probs = class_counts / len(y)
        return 1 - np.sum(class_probs ** 2)
    
    def _get_feature_subset(self, n_features):
        """获取特征子集索引"""
        if self.max_features == 'sqrt':
            subset_size = int(np.sqrt(n_features))
        elif self.max_features == 'log2':
            subset_size = int(np.log2(n_features))
        elif isinstance(self.max_features, int):
            subset_size = min(self.max_features, n_features)
        elif isinstance(self.max_features, float):
            subset_size = int(self.max_features * n_features)
        else: 
            subset_size = n_features
        return np.random.choice(n_features, size=subset_size, replace=False)
    
    def _find_best_split(self, X, y):
        """寻找最佳分裂特征和阈值"""
        best_gini = float('inf')
        best_feature = None
        best_threshold = None
        n_samples, n_features = X.shape
        feature_indices = self._get_feature_subset(n_features)
        for feature_idx in feature_indices:
            feature_values = X[:, feature_idx]
            unique_values = np.unique(feature_values)
            for threshold in unique_values:
                left_mask = feature_values <= threshold
                right_mask = ~left_mask
                if (np.sum(left_mask) < self.min_samples_leaf or 
                    np.sum(right_mask) < self.min_samples_leaf):
                    continue
                left_gini = self._gini_impurity(y[left_mask])
                right_gini = self._gini_impurity(y[right_mask])
                n_left = len(y[left_mask])
                n_right = len(y[right_mask])
                weighted_gini = (n_left * left_gini + n_right * right_gini) / n_samples
                if weighted_gini < best_gini:
                    best_gini = weighted_gini
                    best_feature = feature_idx
                    best_threshold = threshold
        return best_feature, best_threshold, best_gini
    
    def _calculate_leaf_value(self, y):
        """计算叶节点的预测值（多数投票）"""
        if len(y) == 0:
            return 0
        class_counts = np.bincount(y)
        return np.argmax(class_counts)
    
    def _build_tree(self, X, y, depth=0):
        """递归构建决策树"""
        n_samples, n_features = X.shape
        if (depth >= self.max_depth or 
            n_samples < self.min_samples_split or
            len(np.unique(y)) == 1):
            leaf_value = self._calculate_leaf_value(y)
            return TreeNode(value=leaf_value, gini=self._gini_impurity(y), samples=n_samples)
        feature_idx, threshold, gini = self._find_best_split(X, y)
        if feature_idx is None:
            leaf_value = self._calculate_leaf_value(y)
            return TreeNode(value=leaf_value, gini=gini, samples=n_samples)
        left_mask = X[:, feature_idx] <= threshold
        right_mask = ~left_mask
        if (np.sum(left_mask) < self.min_samples_leaf or 
            np.sum(right_mask) < self.min_samples_leaf):
            leaf_value = self._calculate_leaf_value(y)
            return TreeNode(value=leaf_value, gini=gini, samples=n_samples)
        left_subtree = self._build_tree(X[left_mask], y[left_mask], depth + 1)
        right_subtree = self._build_tree(X[right_mask], y[right_mask], depth + 1)
        return TreeNode(
            feature_index=feature_idx,
            threshold=threshold,
            left=left_subtree,
            right=right_subtree,
            gini=gini,
            samples=n_samples
        )
    
    def _predict_single(self, x, tree):
        """对单个样本进行预测"""
        if tree.value is not None: 
            return tree.value
        if x[tree.feature_index] <= tree.threshold:
            return self._predict_single(x, tree.left)
        else:
            return self._predict_single(x, tree.right)
    
    def _predict_proba_single(self, x, tree):
        """对单个样本进行概率预测"""
        if tree.value is not None:
            proba = np.zeros(self.n_classes_)
            if tree.value < self.n_classes_:
                proba[tree.value] = 1.0
            else:
                proba = np.ones(self.n_classes_) / self.n_classes_
            return proba
        
        if x[tree.feature_index] <= tree.threshold:
            return self._predict_proba_single(x, tree.left)
        else:
            return self._predict_proba_single(x, tree.right)
    
    def fit(self, X, y):
        """训练决策树"""
        X = np.array(X)
        y = np.array(y)
        
        self.n_features_ = X.shape[1]
        self.classes_ = np.unique(y)
        self.n_classes_ = len(self.classes_)
        self.tree = self._build_tree(X, y)
        return self
    
    def predict(self, X):
        """预测类别"""
        X = np.array(X)
        return np.array([self._predict_single(x, self.tree) for x in X])
    
    def predict_proba(self, X):
        """预测概率"""
        X = np.array(X)
        probas = np.array([self._predict_proba_single(x, self.tree) for x in X])
        return probas
    
    def score(self, X, y):
        """计算准确率"""
        predictions = self.predict(X)
        return np.mean(predictions == y)
    
    def get_params(self, deep=True):
        """获取模型参数（用于网格搜索）"""
        return {
            'max_depth': self.max_depth,
            'min_samples_split': self.min_samples_split,
            'min_samples_leaf': self.min_samples_leaf,
            'max_features': self.max_features,
            'random_state': self.random_state
        }
    
    def set_params(self, **parameters):
        """设置模型参数（用于网格搜索）"""
        for parameter, value in parameters.items():
            setattr(self, parameter, value)
        return self

class CustomRandomForest:
    """
    完全自定义的随机森林实现（使用自定义决策树）
    """
    def __init__(self, n_estimators=100, max_depth=None, max_features='auto', 
                 random_state=None, bootstrap=True, oob_score=False,
                 min_samples_split=2, min_samples_leaf=1):
        """
        初始化自定义随机森林
        
        参数:
        - n_estimators: 树的数量
        - max_depth: 树的最大深度
        - max_features: 每次分裂时考虑的特征数
        - random_state: 随机种子
        - bootstrap: 是否使用bootstrap采样
        - oob_score: 是否计算袋外分数
        - min_samples_split: 分裂所需最小样本数
        - min_samples_leaf: 叶节点最小样本数
        """
        self.n_estimators = n_estimators
        self.max_depth = max_depth
        self.max_features = max_features
        self.random_state = random_state
        self.bootstrap = bootstrap
        self.oob_score = oob_score
        self.min_samples_split = min_samples_split
        self.min_samples_leaf = min_samples_leaf
        self.estimators_ = []
        self.feature_indices_ = []
        self.oob_score_ = None
        self.n_features_ = None
        self.n_classes_ = None
        self.classes_ = None
        
        if random_state is not None:
            np.random.seed(random_state)
    
    def _bootstrap_sample(self, n_samples, tree_index):
        """Bootstrap采样"""
        indices = np.random.choice(n_samples, size=n_samples, replace=True)
        return indices
    
    def _get_max_features(self, n_features):
        """确定每次分裂考虑的特征数"""
        if self.max_features == 'auto':
            return int(np.sqrt(n_features))
        elif self.max_features == 'sqrt':
            return int(np.sqrt(n_features))
        elif self.max_features == 'log2':
            return int(np.log2(n_features))
        elif isinstance(self.max_features, int):
            return min(self.max_features, n_features)
        elif isinstance(self.max_features, float):
            return int(self.max_features * n_features)
        else:
            return n_features
    
    def _calculate_oob_score(self, X, y):
        """计算袋外分数"""
        n_samples = X.shape[0]
        oob_predictions = np.zeros((n_samples, self.n_classes_))
        oob_counts = np.zeros(n_samples) 
        for i, (tree, feature_indices) in enumerate(zip(self.estimators_, self.feature_indices_)):
            all_indices = set(range(n_samples))
            bootstrap_indices = set(self._bootstrap_sample_indices[i])
            oob_indices = list(all_indices - bootstrap_indices)
            if oob_indices:
                X_oob = X[oob_indices]
                X_oob_subset = X_oob[:, feature_indices]
                oob_pred_proba = tree.predict_proba(X_oob_subset)
                for j, idx in enumerate(oob_indices):
                    if oob_pred_proba[j].shape[0] == self.n_classes_:
                        oob_predictions[idx] += oob_pred_proba[j]
                    else:
                        adjusted_proba = np.zeros(self.n_classes_)
                        min_len = min(len(oob_pred_proba[j]), self.n_classes_)
                        adjusted_proba[:min_len] = oob_pred_proba[j][:min_len]
                        oob_predictions[idx] += adjusted_proba
                    oob_counts[idx] += 1
        if np.any(oob_counts > 0):
            valid_indices = oob_counts > 0
            final_predictions = np.argmax(oob_predictions[valid_indices], axis=1)
            self.oob_score_ = np.mean(final_predictions == y[valid_indices])
    
    def fit(self, X, y):
        """
        训练随机森林
        
        参数:
        - X: 训练特征
        - y: 训练标签
        """
        X = np.array(X)
        y = np.array(y)
        n_samples, n_features = X.shape
        self.n_features_ = n_features
        self.classes_ = np.unique(y)
        self.n_classes_ = len(self.classes_)
        max_features = self._get_max_features(n_features)
        self._bootstrap_sample_indices = []
        if self.oob_score:
            oob_predictions = np.zeros((n_samples, self.n_classes_))
            oob_counts = np.zeros(n_samples)
        self.estimators_ = []
        self.feature_indices_ = []
        for i in range(self.n_estimators):
            if self.bootstrap:
                indices = self._bootstrap_sample(n_samples, i)
                self._bootstrap_sample_indices.append(indices)
            else:
                indices = np.arange(n_samples)
                self._bootstrap_sample_indices.append(indices)
            X_bootstrap = X[indices]
            y_bootstrap = y[indices]
            feature_indices = np.random.choice(n_features, size=max_features, replace=False)
            X_bootstrap_subset = X_bootstrap[:, feature_indices]
            tree = CustomDecisionTree(
                max_depth=self.max_depth,
                min_samples_split=self.min_samples_split,
                min_samples_leaf=self.min_samples_leaf,
                max_features=self.max_features,
                random_state=self.random_state + i if self.random_state else None
            )
            tree.classes_ = self.classes_
            tree.n_classes_ = self.n_classes_  
            tree.fit(X_bootstrap_subset, y_bootstrap)
            self.estimators_.append(tree)
            self.feature_indices_.append(feature_indices)
            if self.oob_score:
                all_indices = set(range(n_samples))
                bootstrap_indices = set(indices)
                oob_indices = list(all_indices - bootstrap_indices)
                if oob_indices:
                    X_oob = X[oob_indices]
                    X_oob_subset = X_oob[:, feature_indices]
                    oob_pred_proba = tree.predict_proba(X_oob_subset)
                    for j, idx in enumerate(oob_indices):
                        if oob_pred_proba[j].shape[0] == self.n_classes_:
                            oob_predictions[idx] += oob_pred_proba[j]
                        else:
                            adjusted_proba = np.zeros(self.n_classes_)
                            min_len = min(len(oob_pred_proba[j]), self.n_classes_)
                            adjusted_proba[:min_len] = oob_pred_proba[j][:min_len]
                            oob_predictions[idx] += adjusted_proba
                        oob_counts[idx] += 1
        if self.oob_score and np.any(oob_counts > 0):
            valid_indices = oob_counts > 0
            final_predictions = np.argmax(oob_predictions[valid_indices], axis=1)
            self.oob_score_ = np.mean(final_predictions == y[valid_indices])
        
        return self
    
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
        X = np.array(X)
        n_samples = X.shape[0]
        all_probas = []
        for tree, feature_indices in zip(self.estimators_, self.feature_indices_):
            X_subset = X[:, feature_indices]
            proba = tree.predict_proba(X_subset)
            if proba.shape[1] != self.n_classes_:
                adjusted_proba = np.zeros((n_samples, self.n_classes_))
                min_len = min(proba.shape[1], self.n_classes_)
                adjusted_proba[:, :min_len] = proba[:, :min_len]
                all_probas.append(adjusted_proba)
            else:
                all_probas.append(proba)
        avg_proba = np.mean(all_probas, axis=0)
        return avg_proba
    
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
        """获取模型参数（用于网格搜索）"""
        return {
            'n_estimators': self.n_estimators,
            'max_depth': self.max_depth,
            'max_features': self.max_features,
            'random_state': self.random_state,
            'bootstrap': self.bootstrap,
            'oob_score': self.oob_score,
            'min_samples_split': self.min_samples_split,
            'min_samples_leaf': self.min_samples_leaf
        }
    
    def set_params(self, **parameters):
        """设置模型参数（用于网格搜索）"""
        for parameter, value in parameters.items():
            setattr(self, parameter, value)
        return self