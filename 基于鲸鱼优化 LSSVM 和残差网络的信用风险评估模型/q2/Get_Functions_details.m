% 
% function [lb,ub,dim,fobj] = Get_Functions_details(F)
% 
% % 将目标函数句柄设置为函数 F1 的句柄
% % @F1 表示函数 F1 的句柄
% % 它可以在后续代码中直接调用 F1 函数
%     switch F
%         case 'F1'
%             fobj =  @F1;
%             lb   =  [0, 0];             % 待优化参数的下限值
%             ub   =  [6000, 200];        % 待优化参数的上限值
%             dim  =  2 ;                 % 输入待优化参数个数
%     end
% end
% 
% 
% function [o, acc] = F1(x)
%     filename = '../data/Ger2.csv';
%     S = readmatrix(filename);
%     temp = randperm(size(S,1),1200)';
%     St = S(temp, :);
%     Y = St(:, 25);
%     St = St(:, 1:20);
% 
%     % S = [0:0.1:20]';%生成200个样本
%     % temp = randperm(size(S,1),180)';
%     % St = S(temp);%随机取180个样本作为训练样本，其余的样本作为测试样本
%     % Y = sin(St);
% 
%     % 高斯核函数
%     n = size(St,1);
%     C = x(1);
%     delta = x(2);
%     dist = pdist2(St,St);
%     Kenel_Matrix = exp(-dist.^2/(2*delta*delta));
% 
%     %最小二乘支持向量回归
%     b_alpha = inv([[0,ones(1,n)];[ones(n,1),Kenel_Matrix+eye(n)/C]])*[0;Y];
%     b = b_alpha(1);
%     a = b_alpha(2:end);
% 
%     %预测部分
%     X = S(setdiff([1:size(S,1)]',temp),:);%主要是获取输入数据
%     for i=1:size(X,1)
%         x = X(i, 1:20);
%         dist = pdist2(St,x);
%         K = exp(-dist.^2/(2*delta*delta));
%         y = sum(a.*K)+b;
%         YX(i,:) = [y,X(i, 25)];
%     end
% 
%     % 计算RMSE误差
%     N = length(X);
%     u = 0;
%     for i=1:N
%         u = u+(YX(i,1)-YX(i,2)).^2;
%     end
% 
%     % 设置阈值
%     threshold = 0.5;
% 
%     % 转换预测值为二元分类标签
%     predicted_labels = YX(:, 1) >= threshold;
% 
%     % 实际标签
%     actual_labels = YX(:, 2);
% 
%     acc = sum(predicted_labels == actual_labels) / length(actual_labels) * 100;
% 
%     o = sqrt(u);
% 
% end


function [lb,ub,dim,fobj] = Get_Functions_details(F)

% 将目标函数句柄设置为函数 F1 的句柄
% @F1 表示函数 F1 的句柄
% 它可以在后续代码中直接调用 F1 函数
    switch F
        case 'F1'
            fobj =  @F1;
            lb   =  [0, 0];             % 待优化参数的下限值
            ub   =  [6000, 200];        % 待优化参数的上限值
            dim  =  2 ;                 % 输入待优化参数个数
    end
end


function [o, acc] = F1(x)
    filename = '../data/Ger3.csv';
    S = readmatrix(filename);
    temp = randperm(size(S,1),1200)';
    St = S(temp, :);
    Y = St(:, 15);
    St = St(:, 1:14);
    
    % 高斯核函数
    n = size(St,1);
    C = x(1);
    delta = x(2);
    dist = pdist2(St,St);
    Kenel_Matrix = exp(-dist.^2/(2*delta*delta));
    
    %最小二乘支持向量回归
    b_alpha = inv([[0,ones(1,n)];[ones(n,1),Kenel_Matrix+eye(n)/C]])*[0;Y];
    b = b_alpha(1);
    a = b_alpha(2:end);
    
    %预测部分
    X = S(setdiff([1:size(S,1)]',temp),:);%主要是获取输入数据
    for i=1:size(X,1)
        x = X(i, 1:14);
        dist = pdist2(St,x);
        K = exp(-dist.^2/(2*delta*delta));
        y = sum(a.*K)+b;
        YX(i,:) = [y,X(i, 15)];
    end

    % 计算RMSE误差
    N = length(X);
    u = 0;
    for i=1:N
        u = u+(YX(i,1)-YX(i,2)).^2;
    end

    % 设置阈值
    threshold = 0.5;
    
    % 转换预测值为二元分类标签
    predicted_labels = YX(:, 1) >= threshold;
    
    % 实际标签
    actual_labels = YX(:, 2);

    acc = sum(predicted_labels == actual_labels) / length(actual_labels) * 100;

    o = sqrt(u);

end


