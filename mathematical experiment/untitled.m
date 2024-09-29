% 准备数据
decision_matrix = [
    80  0.6  0.7;
    90  0.8  0.5;
    70  0.7  0.4;
    85  0.5  0.6;
];

% 标准化数据
normalized_matrix = decision_matrix;
for i = 1:size(decision_matrix, 2)
    normalized_matrix(:, i) = decision_matrix(:, i) / sum(decision_matrix(:, i));
end

% 计算属性的熵值
entropy_values = zeros(1, size(normalized_matrix, 2));
for i = 1:size(normalized_matrix, 2)
    probabilities = normalized_matrix(:, i) / sum(normalized_matrix(:, i));
    entropy_values(i) = -sum(probabilities .* log2(probabilities));
end

% 计算属性的权重
weights = entropy_values / sum(entropy_values);

% 归一化属性权重
normalized_weights = weights / sum(weights);

disp("属性的信息效用值为：");
disp(normalized_weights);