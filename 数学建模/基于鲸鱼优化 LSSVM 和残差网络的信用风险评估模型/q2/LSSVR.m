% http://t.csdnimg.cn/nla38


% 随机取点训练
S = [0:0.1:20]';%生成200个样本
temp = randperm(size(S,1),180)';
St = S(temp);%随机取180个样本作为训练样本，其余的样本作为测试样本
Y = sin(St);

% 高斯核函数
n = size(St,1);
% C = 100;
% delta = 1;
C = 6000;
delta = 0.7573012;
dist = pdist2(St,St);
Kenel_Matrix = exp(-dist.^2/(2*delta*delta));

%最小二乘支持向量回归
b_alpha = inv([[0,ones(1,n)];[ones(n,1),Kenel_Matrix+eye(n)/C]])*[0;Y];
b = b_alpha(1);
a = b_alpha(2:end);

%预测部分
X = S(setdiff([1:size(S,1)]',temp),:);%主要是获取输入数据
for i=1:size(X,1)
    x = X(i,:);
    dist = pdist2(St,x);
    K = exp(-dist.^2/(2*delta*delta));
    y = sum(a.*K)+b;
    YX(i,:) = [y,sin(x)];
end

% 计算误差
N = length(X);
    u = 0;
    for i=1:N
        u = u+(YX(i,1)-YX(i,2)).^2;
    end
    o = sqrt(u);

fprintf('C的值为：%d\n', C);
fprintf('delta的值为：%d\n', delta);
fprintf('误差：%d\n', o);

figure
plot(X,YX(:,1),'-r*','LineWidth',2)
hold on
plot(X,YX(:,2),'-bo','LineWidth',2)
gca = legend('LSSVR','random sin(x)');
set(gca,'FontSize',12);