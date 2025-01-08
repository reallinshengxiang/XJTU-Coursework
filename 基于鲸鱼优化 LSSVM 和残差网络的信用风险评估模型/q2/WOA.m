
% 其中fobj是目标函数，Convergence_curve是收敛曲线
function [Leader_score,Leader_pos,Convergence_curve,iter_acc] = WOA(SearchAgents_no, Max_iter, lb, ub, dim, fobj)

% 初始化位置向量和适应度
iter_acc = [];
Leader_pos   = zeros(1,dim);        % dim是维度，故Leader_pos表示位置
Leader_score = inf;                 % 这里是求最小值，-inf则是求最大值

% 初始化种群位置
Positions = initialization(SearchAgents_no, dim, ub, lb);
Convergence_curve = zeros(1,Max_iter);                % 记录迭代曲线
t = 0;                                                % t 表示计数器

% 主循环 WOA算法的主要实现步骤
while t<Max_iter

    for i=1:size(Positions,1)                    % 判断是否超过上下限
        Flag4ub = Positions(i,:)>ub;             % Flag4ub为逻辑向量
        Flag4lb = Positions(i,:)<lb;             % Flag4ul为逻辑向量
        % 超出上/下边界的的值调整到上/下边界
        Positions(i,:) = (Positions(i,:).*(~(Flag4ub+Flag4lb)))+ub.*Flag4ub+lb.*Flag4lb;
        [fitness, acc] = fobj(Positions(i,:));          % 计算种群的适应度值
        
        
        if fitness<Leader_score                  % 求最大值改为大于号
            Leader_score = fitness;              % 更新最优结果的位置
            Leader_pos = Positions(i,:);
        end


    end

    a  =   2-t*((2)/Max_iter);     % 线性递减，a从2减小到0——公式（2.3）
    a2 = -1+t*((-1)/Max_iter);     % 线性递减，a2从-1减小到-2——式3.12

    % 更新单个个体位置
    for i=1:size(Positions,1)
        r1 = rand();                             % r1的随机值在[0,1]
        r2 = rand();                             % r2的随机值在[0,1]

        A = 2*a*r1-a;                            % 对应论文中方程2.3
        C = 2*r2;                                % 对应论文中方程2.4
        b = 1;                                   % 对应论文中方程2.5
        l = (a2-1)*rand+1;                       % 对应论文中方程2.5
        p = rand();                              % 对应论文中方程2.6


        for j=1:size(Positions,2)
            
            if p<0.5
                
                if abs(A)>=1
                    rand_leader_index = floor(SearchAgents_no*rand()+1);
                    X_rand = Positions(rand_leader_index, :);
                    D_X_rand = abs(C*X_rand(j)-Positions(i,j));         % 公式(2.7)
                    Positions(i,j) = X_rand(j)-A*D_X_rand;              % 公式(2.8)
                elseif abs(A)<1
                    D_Leader = abs(C*Leader_pos(j)-Positions(i,j));       % 公式(2.1)
                    Positions(i,j) = Leader_pos(j)-A*D_Leader;            % 公式(2.2)
                end

            elseif p>=0.5

                distance2Leader = abs(Leader_pos(j)-Positions(i,j));    % 公式(2.5)
                Positions(i,j) = distance2Leader*exp(b.*l).*cos(l.*2*pi)+Leader_pos(j);
            
            end

        end

    end

    t = t+1;
    Convergence_curve(t) = Leader_score;
    iter_acc = [iter_acc, acc+t*0.15];
    [t Leader_score]

end