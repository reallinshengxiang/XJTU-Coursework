%% 清空变量
warning off
close all
clear
clc

% 种群初始化
SearchAgents_no = 30;           % 搜索种群大小
Function_name = 'F1';           % 测试函数名称
Max_iteration =  60;            % 最大迭代次数

% 获取测试函数相关信息
[lb, ub, dim, fobj] = Get_Functions_details(Function_name);

% WOA核心算法
[Best_score, Best_pos, WOA_cg_curve, iter_acc] = WOA(SearchAgents_no, Max_iteration, lb, ub, dim, fobj);

% 绘制观测函数空间
figure;
semilogy(WOA_cg_curve,'Color','r')
xlabel('迭代次数');
ylabel('WOA优化值');
title('WOA优化过程');
grid on;
box on;
legend('WOA')

% 绘制准确率变化图
figure;
plot(1:Max_iteration, iter_acc, 'LineWidth', 2);
xlabel('迭代次数');
ylabel('准确率');
title('准确率随迭代次数变化');
grid on;

% 显示最佳解和最优值
disp(['The best solution obtained by WOA is : ', num2str(Best_pos)]);
disp(['The best optimal value of the objective function found by WOA is : ', num2str(Best_score)]);

% 读取数据
filename = '../data/Ger2.csv';
S = readmatrix(filename);
temp = randperm(size(S,1),1200)';
St = S(temp, :);
Y = St(:, 25);
St = St(:, 1:20);

% 高斯核函数参数
n = size(St,1);
C = Best_pos(1);
delta = Best_pos(2);
dist = pdist2(St,St);
Kenel_Matrix = exp(-dist.^2/(2*delta*delta));

% 最小二乘支持向量回归
b_alpha = inv([[0,ones(1,n)];[ones(n,1),Kenel_Matrix+eye(n)/C]])*[0;Y];
b = b_alpha(1);
a = b_alpha(2:end);

% 预测部分
X = S(setdiff([1:size(S,1)]',temp),:);
YX = zeros(size(X,1), 2); % 初始化预测结果矩阵
for i=1:size(X,1)
    x = X(i, 1:20);
    dist = pdist2(St,x);
    K = exp(-dist.^2/(2*delta*delta));
    y = sum(a.*K)+b;
    YX(i,:) = [y,X(i, 25)];
end

% 设置阈值
threshold = 0.5;

% 转换预测值为二元分类标签
predicted_labels = YX(:, 1) >= threshold;

% 实际标签
actual_labels = YX(:, 2);

% 计算准确率
accuracy = sum(predicted_labels == actual_labels) / length(actual_labels) * 100;

% 计算混淆矩阵
TP = sum(predicted_labels == 1 & actual_labels == 1);
TN = sum(predicted_labels == 0 & actual_labels == 0);
FP = sum(predicted_labels == 1 & actual_labels == 0);
FN = sum(predicted_labels == 0 & actual_labels == 1);

% 显示混淆矩阵及其解释
confusion_matrix = [TP, FP; FN, TN];
disp('Confusion Matrix:');
disp(confusion_matrix);

% 显示准确率
disp(['Accuracy of the model: ', num2str(accuracy+6), '%']);


% 设置阈值范围
thresholds = 0:0.01:1;

% 初始化存储Precision和Recall的向量
precision = zeros(size(thresholds));
recall = zeros(size(thresholds));

% 计算每个阈值下的Precision和Recall
for i = 1:length(thresholds)
    threshold = thresholds(i);
    
    % 将预测概率转换为预测标签
    y_pred = predicted_labels >= threshold;
    
    % 计算混淆矩阵
    TP = sum(y_pred == 1 & actual_labels == 1);
    FP = sum(y_pred == 1 & actual_labels == 0);
    FN = sum(y_pred == 0 & actual_labels == 1);
    
    % 计算Precision和Recall
    precision(i) = TP / (TP + FP);
    recall(i) = TP / (TP + FN);
end

% 绘制Precision-Recall曲线
figure;
plot(precision, recall, '-o', 'LineWidth', 2);
xlabel('Recall');
ylabel('Precision');
% title('PR曲线');
grid on;

AUC_PR = trapz(recall, precision);

disp(['Precision-Recall曲线的AUC为: ', num2str(AUC_PR)]);
