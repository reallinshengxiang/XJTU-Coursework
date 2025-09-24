import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, roc_auc_score, confusion_matrix, precision_recall_curve, auc
from sklearn.model_selection import train_test_split
import itertools

# 读取 Ger.csv 文件
df = pd.read_csv('data/Aus1.csv')
plt.rcParams['font.sans-serif'] = ['SimHei']  # 指定默认字体
plt.rcParams['axes.unicode_minus'] = False  # 解决保存图像是负号'-'显示为方块的问题

# 设置重复运行模型的次数
num_iterations = 10
accuracies = []
auc_scores = []
type1_errors = []
type2_errors = []

for i in range(num_iterations):
    # 随机选择训练集和验证集
    X_train, X_val, y_train, y_val = train_test_split(df.iloc[:, :14], df.iloc[:, -1], train_size=600, shuffle=True)

    # 创建随机森林模型
    rf_model = RandomForestClassifier(n_estimators=100, max_depth=10, random_state=42)

    # 在训练集上训练模型
    rf_model.fit(X_train, y_train)

    # 在验证集上进行预测
    y_pred = rf_model.predict(X_val)
    y_pred_proba = rf_model.predict_proba(X_val)[:, 1]

    # 计算准确率
    accuracy = accuracy_score(y_val, y_pred)
    accuracies.append(accuracy)

    # 计算AUC
    auc1 = roc_auc_score(y_val, y_pred_proba)
    auc_scores.append(auc1)

    # 计算混淆矩阵
    cm = confusion_matrix(y_val, y_pred)
    tn, fp, fn, tp = cm.ravel()

    # 计算Type I error 和 Type II error
    type1_error = fp / (fp + tn)  # Type I error: False Positive Rate
    type2_error = fn / (fn + tp)  # Type II error: False Negative Rate

    type1_errors.append(type1_error)
    type2_errors.append(type2_error)

    print(f'Iteration {i+1}: Accuracy: {accuracy:.4f}, AUC: {auc1:.4f}, Type I error: {type1_error:.4f}, Type II error: {type2_error:.4f}')

# 计算平均值和标准差
mean_accuracy = np.mean(accuracies)
std_accuracy = np.std(accuracies)
mean_auc = np.mean(auc_scores)
std_auc = np.std(auc_scores)
mean_type1_error = np.mean(type1_errors)
std_type1_error = np.std(type1_errors)
mean_type2_error = np.mean(type2_errors)
std_type2_error = np.std(type2_errors)

print(f'\nAverage accuracy on validation set: {mean_accuracy:.4f} ± {std_accuracy:.4f}')
print(f'Average AUC on validation set: {mean_auc:.4f} ± {std_auc:.4f}')
print(f'Average Type I error on validation set: {mean_type1_error:.4f} ± {std_type1_error:.4f}')
print(f'Average Type II error on validation set: {mean_type2_error:.4f} ± {std_type2_error:.4f}')


# 绘制混淆矩阵的函数
def plot_confusion_matrix(cm, classes,
                          normalize=False,
                          title='Confusion matrix',
                          cmap=plt.cm.Blues):
    """
    This function prints and plots the confusion matrix.
    Normalization can be applied by setting `normalize=True`.
    """
    if normalize:
        cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]
        print("Normalized confusion matrix")
    else:
        print('Confusion matrix, without normalization')

    plt.imshow(cm, interpolation='nearest', cmap=cmap)
    plt.title(title)
    plt.colorbar()
    tick_marks = np.arange(len(classes))
    plt.xticks(tick_marks, classes, rotation=45)
    plt.yticks(tick_marks, classes)

    fmt = '.2f' if normalize else 'd'
    thresh = cm.max() / 2.
    for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
        plt.text(j, i, format(cm[i, j], fmt),
                 horizontalalignment="center",
                 color="white" if cm[i, j] > thresh else "black")

    plt.ylabel('真实')
    plt.xlabel('预测')
    plt.tight_layout()

# 可视化混淆矩阵
plt.figure()
cm = confusion_matrix(y_val, y_pred)
plt.imshow(cm, interpolation='nearest', cmap=plt.cm.Greens)  # 使用Greens颜色映射
plot_confusion_matrix(cm, classes=['正样本', '负样本'], title='混淆矩阵')

plt.show()

# 计算精确度-召回率曲线
precision, recall, _ = precision_recall_curve(y_val, y_pred_proba)

# 计算AUC(PR曲线下面积)
pr_auc = auc(recall, precision)

# 绘制PR曲线
plt.figure()
plt.plot(recall, precision, color='darkorange', lw=2, label='PR曲线')
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.05])
plt.xlabel('Recall')
plt.ylabel('Precision')
plt.legend(loc="lower right")
plt.show()
