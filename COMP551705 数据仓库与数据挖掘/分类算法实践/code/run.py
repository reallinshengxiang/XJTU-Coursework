from scipy.io import arff
import numpy as np
from sklearn.model_selection import train_test_split, cross_val_score, GridSearchCV
from sklearn.preprocessing import LabelEncoder
import pandas as pd
from sklearn.pipeline import Pipeline
from sklearn.feature_selection import VarianceThreshold
from sklearn.ensemble import RandomForestClassifier, AdaBoostClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.preprocessing import StandardScaler
from sklearn.impute import SimpleImputer
from sklearn.feature_selection import SelectKBest
from sklearn.cluster import KMeans
from sklearn.metrics import confusion_matrix, classification_report, accuracy_score
import matplotlib.pyplot as plt
import seaborn as sns
import argparse
import sys
import os
import warnings
from datetime import datetime
import json
sys.path.append(os.path.join(os.path.dirname(__file__), 'models'))
warnings.filterwarnings('ignore')
from Orange.classification import TreeLearner
from Orange.data import Table, Domain, ContinuousVariable, DiscreteVariable
from models.custom_randomforest import CustomRandomForest
from models.custom_knn import CustomKNN
from models.custom_naivebayes import CustomNaiveBayes

def load_data(filename):
    filename = 'dataset_183/{}.arff'.format(filename)
    data, meta = arff.loadarff(filename)
    df = pd.DataFrame(data)
    target_column = df.columns[-1]  
    print(f"检测到的目标列: {target_column}")
    y = df[target_column]
    encoder = LabelEncoder()
    y = encoder.fit_transform(y)
    X = df.drop(columns=[target_column])
    for column in X.columns:
        if X[column].dtype == object: 
            try:
                X[column] = X[column].astype(float)
            except ValueError:
                le = LabelEncoder()
                X[column] = le.fit_transform(X[column])
    return X, y

def split_data(X, y, test_size=0.2, random_state=42):
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=test_size, random_state=random_state)
    return X_train, X_test, y_train, y_test 

class OrangeC45Wrapper:
    """使用Orange3的C4.5实现"""
    def __init__(self, random_state=None):
        self.clf = None
        self.model = None
        self.random_state = random_state
        
    def fit(self, X, y):
        feature_vars = [ContinuousVariable(f"feature_{i}") for i in range(X.shape[1])]
        class_values = [str(i) for i in np.unique(y)]
        class_var = DiscreteVariable("class", values=class_values)
        domain = Domain(feature_vars, class_var)
        X_table = X.astype(float)
        y_table = y.astype(str).reshape(-1, 1)
        data = np.hstack([X_table, y_table])
        table = Table.from_numpy(domain, data)
        self.clf = TreeLearner()
        self.model = self.clf(table)
        return self
        
    def predict(self, X):
        if self.model is None:
            raise ValueError("模型尚未训练")
        feature_vars = [ContinuousVariable(f"feature_{i}") for i in range(X.shape[1])]
        domain = Domain(feature_vars)
        table = Table.from_numpy(domain, X.astype(float))
        predictions = self.model(table)
        return np.array([int(p) for p in predictions])
    
    def score(self, X, y):
        predictions = self.predict(X)
        return np.mean(predictions == y)

class KMeansWrapper:
    """K-Means包装器，用于分类任务（通过聚类标签与真实标签的映射）"""
    def __init__(self, n_clusters=None, random_state=42):
        self.n_clusters = n_clusters
        self.random_state = random_state
        self.kmeans = None
        self.label_mapping = None
        
    def fit(self, X, y):
        if self.n_clusters is None:
            self.n_clusters = len(np.unique(y))
        self.kmeans = KMeans(n_clusters=self.n_clusters, random_state=self.random_state)
        cluster_labels = self.kmeans.fit_predict(X)
        self.label_mapping = {}
        for cluster in range(self.n_clusters):
            mask = cluster_labels == cluster
            if np.any(mask):
                true_labels = y[mask]
                most_common = np.bincount(true_labels).argmax()
                self.label_mapping[cluster] = most_common
        return self
        
    def predict(self, X):
        cluster_labels = self.kmeans.predict(X)
        return np.array([self.label_mapping.get(label, 0) for label in cluster_labels])
    
    def score(self, X, y):
        predictions = self.predict(X)
        return np.mean(predictions == y)

def get_classifier(algorithm, n_classes=None):
    """
    根据算法名称返回对应的分类器
    """
    algorithm_lower = algorithm.lower()
    if algorithm_lower == 'svm':
        return SVC(random_state=42, probability=True)
    elif algorithm_lower == 'c4.5':
        return OrangeC45Wrapper(random_state=42)
    elif algorithm_lower == 'adaboost':
        return AdaBoostClassifier(random_state=42)
    elif algorithm_lower == 'randomforest':
        return RandomForestClassifier(n_estimators=100, random_state=42)
    elif algorithm_lower == 'custom_randomforest':
        return CustomRandomForest(n_estimators=100, random_state=42, oob_score=True)
    elif algorithm_lower == 'knn':
        return KNeighborsClassifier(n_neighbors=5)
    elif algorithm_lower == 'custom_knn':
        return CustomKNN(n_neighbors=5, random_state=42)
    elif algorithm_lower == 'naivebayes':
        return GaussianNB()
    elif algorithm_lower == 'custom_naivebayes':
        return CustomNaiveBayes(distribution='gaussian', random_state=42)
    elif algorithm_lower == 'cart':
        return DecisionTreeClassifier(random_state=42)
    elif algorithm_lower == 'kmeans' and n_classes is not None:
        return KMeansWrapper(n_clusters=n_classes, random_state=42)
    else:
        raise ValueError(f"不支持的算法: {algorithm}。支持的算法有: svm, c4.5, adaboost, randomforest, custom_randomforest, knn, custom_knn, naivebayes, custom_naivebayes, cart, kmeans")

def get_param_grid(algorithm):
    """
    根据算法名称返回对应的参数网格
    """
    algorithm_lower = algorithm.lower()
    n_estimators = list(range(50, 151, 50)) 
    max_depth = list(range(5, 26, 5)) + [None]
    knn_neighbors = list(range(3, 12, 2))
    
    if algorithm_lower == 'svm':
        return {
            'classifier__C': [0.1, 1, 10],
            'classifier__kernel': ['linear', 'rbf', 'poly'],
            'classifier__gamma': ['scale', 'auto', 0.001, 0.01]
        }
    elif algorithm_lower == 'adaboost':
        return {
            'classifier__n_estimators': n_estimators,
            'classifier__learning_rate': [0.01, 0.1, 1.0],
            'classifier__algorithm': ['SAMME', 'SAMME.R']
        }
    elif algorithm_lower == 'randomforest':
        return {
            'classifier__n_estimators': n_estimators,
            'classifier__max_depth': max_depth,
            'classifier__min_samples_split': [2, 5],
            'classifier__max_features': ['auto', 'sqrt'],
            'classifier__bootstrap': [True, False]
        }
    elif algorithm_lower == 'custom_randomforest':
        return {
            'n_estimators': n_estimators,
            'max_depth': max_depth,
            'min_samples_split': [2, 5],
            'max_features': ['auto', 'sqrt'],
            'oob_score': [True, False]
        }
    elif algorithm_lower == 'knn':
        return {
            'classifier__n_neighbors': knn_neighbors,
            'classifier__weights': ['uniform', 'distance'],
            'classifier__metric': ['euclidean', 'manhattan']
        }
    elif algorithm_lower == 'custom_knn':
        return {
            'n_neighbors': knn_neighbors,
            'weights': ['uniform', 'distance'],
            'metric': ['euclidean', 'manhattan']
        }
    elif algorithm_lower == 'naivebayes':
        return {
            'classifier__var_smoothing': [1e-9, 1e-8, 1e-7]
        }
    elif algorithm_lower == 'custom_naivebayes':
        return {
            'distribution': ['gaussian', 'multinomial'],
            'var_smoothing': [1e-9, 1e-8, 1e-7],
            'alpha': [0.1, 0.5, 1.0],
            'fit_prior': [True, None]
        }
    elif algorithm_lower == 'cart':
        return {
            'classifier__max_depth': max_depth,
            'classifier__min_samples_split': [2, 5],
            'classifier__criterion': ['gini', 'entropy'],
            'classifier__max_features': ['auto', 'sqrt']
        }
    elif algorithm_lower in ['c4.5', 'kmeans']:
        return None
    else:
        return None

def plot_confusion_matrix(cm, classes, algorithm, dataset, result_dir):
    """绘制并保存混淆矩阵"""
    plt.figure(figsize=(10, 8))
    sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', 
                xticklabels=classes, yticklabels=classes)
    plt.title(f'{algorithm} - Confusion Matrix\nDataset: {dataset}')
    plt.ylabel('Authenticity Label')
    plt.xlabel('Prediction Label')
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    cm_file = f"{result_dir}/confusion_matrix_{algorithm}_{dataset}_{timestamp}.png"
    plt.savefig(cm_file, dpi=300, bbox_inches='tight')
    plt.close()
    return cm_file

def save_results(results, algorithm, dataset, result_dir, cm, class_names):
    """保存结果到文件"""
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    result_file = f"{result_dir}/{algorithm}_{dataset}_{timestamp}.txt"
    with open(result_file, 'w') as f:
        f.write(f"算法: {algorithm}\n")
        f.write(f"数据集: {dataset}\n")
        f.write(f"运行时间: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
        f.write(f"特征数量: {results['initial_features']}\n")
        f.write(f"类别数量: {results['n_classes']}\n")
        if 'best_params' in results:
            f.write(f"最佳参数: {results['best_params']}\n")
        f.write(f"训练集准确率: {results['train_accuracy']:.4f}\n")
        f.write(f"测试集准确率: {results['test_accuracy']:.4f}\n")
        f.write(f"交叉验证准确率: {[f'{score:.4f}' for score in results['accuracy_scores']]}\n")
        f.write(f"平均交叉验证准确率: {results['mean_accuracy']:.4f} (±{results['std_accuracy']:.4f})\n")
        f.write("\n混淆矩阵:\n")
        f.write("行: 真实标签, 列: 预测标签\n")
        np.savetxt(f, cm, fmt='%d', delimiter='\t')
        f.write("\n分类报告:\n")
        f.write("\n详细指标:\n")
        for i in range(len(cm)):
            tp = cm[i, i]
            fp = cm[:, i].sum() - tp
            fn = cm[i, :].sum() - tp
            tn = cm.sum() - tp - fp - fn
            precision = tp / (tp + fp) if (tp + fp) > 0 else 0
            recall = tp / (tp + fn) if (tp + fn) > 0 else 0
            f1 = 2 * precision * recall / (precision + recall) if (precision + recall) > 0 else 0
            f.write(f"类别 {i}:\n")
            f.write(f"  精度 (Precision): {precision:.4f}\n")
            f.write(f"  召回率 (Recall): {recall:.4f}\n")
            f.write(f"  F1分数: {f1:.4f}\n")
        f.write(f"\n总体准确率: {results['test_accuracy']:.4f}\n")
        if algorithm == 'custom_randomforest' and 'oob_score' in results and results['oob_score'] is not None:
            f.write(f"袋外分数 (OOB Score): {results['oob_score']:.4f}\n")
        if algorithm == 'custom_knn' and 'knn_params' in results:
            f.write(f"KNN参数: {results['knn_params']}\n")
        if algorithm == 'custom_naivebayes' and 'nb_params' in results:
            f.write(f"朴素贝叶斯参数: {results['nb_params']}\n")
    json_file = f"{result_dir}/{algorithm}_{dataset}_{timestamp}.json"
    with open(json_file, 'w') as f:
        results['confusion_matrix'] = cm.tolist()
        results['class_names'] = class_names
        json.dump(results, f, indent=4, default=str)
    print(f"结果已保存到: {result_file} 和 {json_file}")
    return result_file, json_file

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='分类算法比较')
    parser.add_argument('--algorithm', type=str, required=True, 
                       choices=['svm', 'c4.5', 'adaboost', 'randomforest', 'custom_randomforest', 
                                'knn', 'custom_knn', 'naivebayes', 'custom_naivebayes', 'cart', 'kmeans'],
                       help='选择分类算法: svm, c4.5, adaboost, randomforest, custom_randomforest, knn, custom_knn, naivebayes, custom_naivebayes, cart, kmeans')
    parser.add_argument('--dataset', type=str, default='autos',
                       help='数据集名称（不包含.arff扩展名）')
    args = parser.parse_args()
    result_dir = f"result/{args.algorithm}"
    os.makedirs(result_dir, exist_ok=True)
    X, y = load_data(args.dataset)
    X_train, X_test, y_train, y_test = split_data(X, y)
    initial_features = X_train.shape[1]
    n_classes = len(np.unique(y))
    class_names = [str(i) for i in range(n_classes)]
    print(f"特征数量: {initial_features}")
    print(f"类别数量: {n_classes}")
    print(f"使用的算法: {args.algorithm}")
    best_classifier = None
    best_params = None
    param_grid = get_param_grid(args.algorithm)
    if param_grid is not None:
        print(f"\n🔍 开始{args.algorithm}算法调参（GridSearchCV）...")
        if args.algorithm.lower() not in ['c4.5', 'kmeans', 'custom_randomforest', 'custom_knn', 'custom_naivebayes']:
            pipeline_steps = [
                ('imputer', SimpleImputer(strategy='most_frequent')),
                ('variance_threshold', VarianceThreshold(threshold=0.01)),
                ('selector', SelectKBest(k=min(9, initial_features))),
            ]
            if args.algorithm.lower() in ['svm', 'knn']:
                pipeline_steps.append(('scaler', StandardScaler()))   
            pipeline_steps.append(('classifier', get_classifier(args.algorithm, n_classes)))
            pipeline = Pipeline(pipeline_steps)
            grid_search = GridSearchCV(
                estimator=pipeline,
                param_grid=param_grid,
                cv=5,
                scoring='accuracy',
                n_jobs=-1,
                verbose=1
            )
            grid_search.fit(X_train, y_train)
            best_classifier = grid_search.best_estimator_
            best_params = grid_search.best_params_
        else:
            imputer = SimpleImputer(strategy='most_frequent')
            X_train_processed = imputer.fit_transform(X_train)
            X_test_processed = imputer.transform(X_test)
            selector = VarianceThreshold(threshold=0.01)
            X_train_processed = selector.fit_transform(X_train_processed)
            X_test_processed = selector.transform(X_test_processed)
            if args.algorithm.lower() in ['knn', 'custom_knn', 'kmeans']:
                scaler = StandardScaler()
                X_train_processed = scaler.fit_transform(X_train_processed)
                X_test_processed = scaler.transform(X_test_processed)
            base_clf = get_classifier(args.algorithm, n_classes)
            grid_search = GridSearchCV(
                estimator=base_clf,
                param_grid=param_grid,
                cv=5,
                scoring='accuracy',
                n_jobs=-1,
                verbose=1
            )
            grid_search.fit(X_train_processed, y_train)
            best_classifier = grid_search.best_estimator_
            best_params = grid_search.best_params_
        print(f"🏆 最佳参数组合: {best_params}")
    else:
        best_classifier = get_classifier(args.algorithm, n_classes)
        best_params = "无需调参"
        print(f"⚠️ {args.algorithm}算法无需调参，使用默认参数")
    cm = None
    y_pred = None
    special_algorithms = ['c4.5', 'kmeans', 'custom_randomforest', 'custom_knn', 'custom_naivebayes']
    if args.algorithm.lower() in special_algorithms:
        print(f"使用{args.algorithm}算法...")
        imputer = SimpleImputer(strategy='most_frequent')
        X_train_processed = imputer.fit_transform(X_train)
        X_test_processed = imputer.transform(X_test)
        selector = VarianceThreshold(threshold=0.01)
        X_train_processed = selector.fit_transform(X_train_processed)
        X_test_processed = selector.transform(X_test_processed)
        if args.algorithm.lower() in ['knn', 'custom_knn', 'kmeans']:
            scaler = StandardScaler()
            X_train_processed = scaler.fit_transform(X_train_processed)
            X_test_processed = scaler.transform(X_test_processed)
        best_classifier.fit(X_train_processed, y_train)
        y_pred = best_classifier.predict(X_test_processed)
        train_accuracy = best_classifier.score(X_train_processed, y_train)
        test_accuracy = best_classifier.score(X_test_processed, y_test)
        print(f"训练集准确率: {train_accuracy:.4f}")
        print(f"测试集准确率: {test_accuracy:.4f}")
        cm = confusion_matrix(y_test, y_pred)
        print("混淆矩阵:")
        print(cm)
        oob_score = None
        if args.algorithm.lower() == 'custom_randomforest' and hasattr(best_classifier, 'oob_score_'):
            oob_score = best_classifier.oob_score_
            if oob_score is not None:
                print(f"袋外分数 (OOB Score): {oob_score:.4f}")
        from sklearn.model_selection import KFold
        kf = KFold(n_splits=5, shuffle=True, random_state=42)
        accuracy_scores = []
        for fold, (train_index, val_index) in enumerate(kf.split(X)):
            X_train_fold, X_val_fold = X.iloc[train_index], X.iloc[val_index]
            y_train_fold, y_val_fold = y[train_index], y[val_index]
            X_train_fold_processed = imputer.fit_transform(X_train_fold)
            X_val_fold_processed = imputer.transform(X_val_fold)
            X_train_fold_processed = selector.fit_transform(X_train_fold_processed)
            X_val_fold_processed = selector.transform(X_val_fold_processed)
            if args.algorithm.lower() in ['knn', 'custom_knn', 'kmeans']:
                X_train_fold_processed = scaler.fit_transform(X_train_fold_processed)
                X_val_fold_processed = scaler.transform(X_val_fold_processed)
            fold_clf = get_classifier(args.algorithm, n_classes)
            if param_grid is not None:
                fold_clf.set_params(**best_params)
            fold_clf.fit(X_train_fold_processed, y_train_fold)
            fold_accuracy = fold_clf.score(X_val_fold_processed, y_val_fold)
            accuracy_scores.append(fold_accuracy)
            print(f"第{fold+1}折交叉验证准确率: {fold_accuracy:.4f}")
        accuracy_scores = np.array(accuracy_scores)
    else:
        y_pred = best_classifier.predict(X_test)
        cm = confusion_matrix(y_test, y_pred)
        print("混淆矩阵:")
        print(cm)
        train_accuracy = best_classifier.score(X_train, y_train)
        test_accuracy = best_classifier.score(X_test, y_test)
        print(f"训练集准确率: {train_accuracy:.4f}")
        print(f"测试集准确率: {test_accuracy:.4f}")
        accuracy_scores = cross_val_score(best_classifier, X, y, cv=5, scoring='accuracy')
        for i, score in enumerate(accuracy_scores):
            print(f"第{i+1}折交叉验证准确率: {score:.4f}")
    mean_accuracy = accuracy_scores.mean()
    std_accuracy = accuracy_scores.std()
    print("交叉验证准确率:", [f"{score:.4f}" for score in accuracy_scores])
    print(f"平均交叉验证准确率: {mean_accuracy:.4f} (±{std_accuracy:.4f})")
    if cm is not None:
        cm_file = plot_confusion_matrix(cm, class_names, args.algorithm, args.dataset, result_dir)
        print(f"混淆矩阵已保存到: {cm_file}")
    results = {
        'algorithm': args.algorithm,
        'dataset': args.dataset,
        'initial_features': initial_features,
        'n_classes': n_classes,
        'best_params': best_params, 
        'train_accuracy': train_accuracy,
        'test_accuracy': test_accuracy,
        'accuracy_scores': accuracy_scores.tolist(),
        'mean_accuracy': mean_accuracy,
        'std_accuracy': std_accuracy,
        'timestamp': datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    }
    if args.algorithm.lower() == 'custom_randomforest' and 'oob_score' in locals():
        results['oob_score'] = oob_score
    if args.algorithm.lower() == 'custom_knn' and hasattr(best_classifier, 'n_neighbors'):
        results['knn_params'] = {
            'n_neighbors': best_classifier.n_neighbors,
            'weights': best_classifier.weights,
            'metric': best_classifier.metric
        }
    if args.algorithm.lower() == 'custom_naivebayes' and hasattr(best_classifier, 'distribution'):
        results['nb_params'] = {
            'distribution': best_classifier.distribution,
            'var_smoothing': best_classifier.var_smoothing,
            'alpha': best_classifier.alpha
        }
    
    txt_file, json_file = save_results(results, args.algorithm, args.dataset, result_dir, cm, class_names)
    plt.figure(figsize=(10,6))
    plt.bar(range(1,6), accuracy_scores, color='skyblue', edgecolor='black')
    plt.axhline(mean_accuracy, color='r', linestyle='--', label=f'Average accuracy: {mean_accuracy:.4f}')
    plt.xlabel('Cross-validation fold count')
    plt.ylabel('Accuracy')   
    algorithm_names = {
        'custom_randomforest': 'Custom Random Forest',
        'custom_knn': 'Custom KNN',
        'custom_naivebayes': 'Custom Naive Bayes',
        'naivebayes': 'Naive Bayes'
    }
    algorithm_name = algorithm_names.get(args.algorithm, args.algorithm.upper())
    plt.title(f'{algorithm_name}Algorithm - 5-fold cross-validation accuracy distribution')
    plt.legend()
    plt.ylim(0, 1.0)
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    plot_file = f"{result_dir}/cross_val_accuracy_{args.algorithm}_{args.dataset}_{timestamp}.png"
    plt.savefig(plot_file, dpi=300, bbox_inches='tight')
    print(f"交叉验证准确率图表已保存到: {plot_file}")
    plt.show()
    summary_file = "result/summary.csv"
    summary_data = {
        'timestamp': datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
        'algorithm': args.algorithm,
        'dataset': args.dataset,
        'features': initial_features,
        'classes': n_classes,
        'best_params': str(best_params), 
        'train_accuracy': f"{train_accuracy:.4f}",
        'test_accuracy': f"{test_accuracy:.4f}",
        'mean_cv_accuracy': f"{mean_accuracy:.4f}",
        'std_cv_accuracy': f"{std_accuracy:.4f}"
    }
    if args.algorithm.lower() == 'custom_randomforest' and 'oob_score' in locals() and oob_score is not None:
        summary_data['oob_score'] = f"{oob_score:.4f}"
    if not os.path.exists(summary_file):
        pd.DataFrame([summary_data]).to_csv(summary_file, index=False)
    else:
        df = pd.read_csv(summary_file)
        df = pd.concat([df, pd.DataFrame([summary_data])], ignore_index=True)
        df.to_csv(summary_file, index=False)
    print(f"结果已汇总到: {summary_file}")
    if y_pred is not None:
        print("\n分类报告:")
        unique_test_classes = np.unique(y_test)
        test_class_names = [str(cls) for cls in unique_test_classes]
        print(classification_report(
            y_test, 
            y_pred, 
            labels=unique_test_classes,
            target_names=test_class_names
        ))