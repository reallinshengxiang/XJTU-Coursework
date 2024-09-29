clear all;clc

h = waitbar(0, 'Processing...');
% 参数定义：
m=8;
num_layer=3;
sp_bad_rate=ones(1, m)*0.1;
sp_cost=[2, 8, 12, 2, 8, 12, 8, 12];
sp_valcost = [1, 1, 2, 1, 1, 2, 1, 2];
half_bad_rate = ones(1, m)*0.1;
num_ini=1*ones(1, m);
num_ini=1*[1.2,1,0.8,1.2,1,0.8,1,0.8];
num_sp=num_ini;
num_half=zeros(3, 1);
num_fin=0;
half_cost=[8, 8, 8];
half_valcost=[4, 4, 4];
half_crash=[6, 6, 6];
fin_bad_rate=0.1;
fin_cost=8;
fin_valcost=6;
fin_crash=10;
ini_sp_bad = sp_bad_rate;   
ini_half_bad = half_bad_rate;
ini_fin_bad = fin_bad_rate;
cur_sp_bad = sp_bad_rate;
cur_half_bad = half_bad_rate;
cur_fin_bad = fin_bad_rate;

buy=200;
ex=40;

rd = 10; %修改

% 决策的表示
% 前八个分别是零配件检不检测（检测1，不检测0）
% 9到11是半成品的检测、拆解和不检测（检测丢弃2，检测拆解1，不检测0）
% 12是成品是否检测（检测1，不检测0）
% 13是全部丢弃还是拆解（1丢弃，0拆解）

pop=2000; %修改
one_r = length(sp_cost) + length(half_cost) + 2;
n=rd * one_r;
M=200; %修改
crossover_prob=0.6; %修改
mutation_prob=0.1; %修改
initial_pop=zeros(pop, n); %修改
best_cost = zeros(1, M); 
for i = 1:pop

    for j = 1:rd
        % 前8个是零配件的检测，取值范围是0或1
        initial_pop(i, 1+13*(j-1):8+13*(j-1)) = randi([0, 1], 1, 8);
        
        % 第9到11是半成品的检测或拆解，取值范围是0, 1, 2
        initial_pop(i, 9+13*(j-1):11+13*(j-1)) = randi([0, 2], 1, 3);
        
        % 第12个是成品检测，取值范围是0或1
        initial_pop(i, 12+13*(j-1)) = randi([0, 1], 1, 1);
        
        % 第13个是丢弃或拆解，取值范围是0或1
        initial_pop(i, 13+13*(j-1)) = randi([0, 1], 1, 1);
    end

end

for g=1:M

    cost=zeros(pop,1);
    fitness=zeros(pop, 1);
    for i=1:pop

        next_round = 0;
        sp_bad_rate=ones(1, m)*0.1;
        half_bad_rate = ones(1, m)*0.1;
        num_ini=1*ones(1, m);
        num_ini=1*[1.2,1,0.8,1.2,1,0.8,1,0.8];
        num_sp=num_ini;
        num_half=zeros(3, 1);
        num_fin=0;
        fin_bad_rate=0.1;
        ini_sp_bad = sp_bad_rate;   
        ini_half_bad = half_bad_rate;
        ini_fin_bad = fin_bad_rate;
        cur_sp_bad = sp_bad_rate;
        cur_half_bad = half_bad_rate;
        cur_fin_bad = fin_bad_rate;

        for j=1:rd

            total_sp = num_ini;

            % 辨别零件费用
            for x=1:length(sp_cost)
                if initial_pop(i, (j-1)*one_r+x) == 1 && cur_sp_bad(x)~=0
                    cost(i) = cost(i)-num_sp(x)*sp_valcost(x);
                    num_sp(x) = num_sp(x) * (1 - cur_sp_bad(x));
                    total_sp(x) = total_sp(x) * (1 - cur_sp_bad(x));
                    cur_sp_bad(x) = 0;
                end
            end

            % 组装半成品费用
            cur_half_bad(1) = (1 - (1-cur_sp_bad(1)) * (1-cur_sp_bad(2)) * (1-cur_sp_bad(3)) * (1-half_bad_rate(1)));
            cur_half_bad(2) = (1 - (1-cur_sp_bad(4)) * (1-cur_sp_bad(5)) * (1-cur_sp_bad(6)) * (1-half_bad_rate(2)));
            cur_half_bad(3) = (1 - (1-cur_sp_bad(7)) * (1-cur_sp_bad(8)) * (1-half_bad_rate(3)));
            num_half(1) = min(num_sp(1:3));
            num_sp(1:3) = num_sp(1:3) - num_half(1);
            num_half(2) = min(num_sp(4:6));
            num_sp(4:6) = num_sp(4:6) - num_half(2);
            num_half(3) = min(num_sp(7:8));
            num_sp(7:8) = num_sp(7:8) - num_half(3);
            cost(i)=cost(i)- num_half(1)*half_cost(1);
            cost(i)=cost(i)- num_half(2)*half_cost(2);
            cost(i)=cost(i)- num_half(3)*half_cost(3);

            % 辨别半成品费用
            for x=length(sp_cost)+1:length(sp_cost)+length(half_cost)
                if initial_pop(i, (j-1)*one_r+x) == 1
                    cost(i) = cost(i)-num_half(x-length(sp_cost))*half_valcost(x-length(sp_cost));

                    % 因为拆了，所以零件的个数和错误率都变了
                    if x == 9
                        num_sp(1:3) = num_sp(1:3) + num_half(x-length(sp_cost)) * cur_half_bad(x-length(sp_cost));
                        cur_sp_bad(1:3) = num_half(1) * cur_sp_bad(1:3) ./ num_sp(1:3);
                    elseif x == 10
                        num_sp(4:6) = num_sp(4:6) + num_half(x-length(sp_cost)) * cur_half_bad(x-length(sp_cost));
                        cur_sp_bad(4:6) = num_half(2) * cur_sp_bad(4:6) ./ num_sp(4:6);
                    elseif x == 11
                        num_sp(7:8) = num_sp(7:8) + num_half(x-length(sp_cost)) * cur_half_bad(x-length(sp_cost));
                        cur_sp_bad(7:8) = num_half(3) * cur_sp_bad(7:8) ./ num_sp(7:8);
                    end

                    % 拆也是要钱的嘛
                    cost(i) = cost(i) - num_half(x-length(sp_cost)) * half_crash(x-length(sp_cost));


                    % 检测带来的个数减少
                    num_half(x-length(sp_cost)) = num_half(x-length(sp_cost)) * (1 - cur_half_bad(x-length(sp_cost)));
                    cur_half_bad(x-length(sp_cost)) = 0;

                elseif initial_pop(i, (j-1)*one_r+x) == 2
                    % 结束直接计算cost
                    cost(i) = cost(i)-num_half(x-length(sp_cost))*half_valcost(x-length(sp_cost));
                    next_round = 1;
                    % 检测带来的个数减少
                    num_half(x-length(sp_cost)) = num_half(x-length(sp_cost)) * (1 - cur_half_bad(x-length(sp_cost)));
                    cur_half_bad(x-length(sp_cost)) = 0;
                end
            end

            % 组装成品的费用
            cur_fin_bad = (1 - (1-cur_half_bad(1)) * (1-cur_half_bad(2)) * (1-cur_half_bad(3)) * (1-fin_bad_rate(1)));
            num_fin = min(num_half);
            num_half = num_half - num_fin;
            cost(i) = cost(i) - fin_cost * num_fin;

            % 成品检测不检测呢(想了想还是直接判断吧)
            cost(i) = cost(i) - min(fin_valcost * num_fin, num_fin * cur_fin_bad * ex) + num_fin * (1 - cur_fin_bad) * buy;
            % 成品丢不丢
               
            if initial_pop(i, (j-1)*one_r + 13) == 0
                % 零件损失只有
                % 算拆解成零件的费用
                cost(i) = cost(i) - num_fin * cur_fin_bad * fin_crash;
                correct_sp = num_ini .* (1 - ini_sp_bad) - num_fin .* (1 - cur_fin_bad);
                total_sp = total_sp - num_fin * (1 - cur_fin_bad);
                % 当半成品次品率小于阈值(50%)的时候才拆
                if cur_half_bad(1) < 0.5
                    % cur_sp_bad(1:3) = (num_sp(1:3) * cur_sp_bad(1:3) + num_half(1) * cur_half_bad(1)) / (num_sp(1:3) + num_half(1));
                    % num_sp(1:3) = num_sp(1:3) + num_half(1);
                    cost(i) = cost(i) - num_half(1) * half_crash(1);
                else
                    correct_sp(1:3) =  correct_sp(1:3) - num_half(1) * (1 - cur_half_bad(1));
                    total_sp(1:3) =  total_sp(1:3) - num_half(1);
                end
        
                if cur_half_bad(2) < 0.5
                    % cur_sp_bad(4:6) = (num_sp(4:6) * cur_sp_bad(4:6) + num_half(2) * cur_half_bad(2)) / (num_sp(4:6) + num_half(2));
                    % num_sp(4:6) = num_sp(4:6) + num_half(2);
                    cost(i) = cost(i) - num_half(2) * half_crash(2);
                else
                    correct_sp(4:6) =  correct_sp(4:6) - num_half(2) * (1 - cur_half_bad(2));
                    total_sp(4:6) =  total_sp(4:6) - num_half(2);
                end
        
                if cur_half_bad(3) < 0.5
                    % cur_sp_bad(7:8) = (num_sp(7:8) * cur_sp_bad(7:8) + num_half(3) * cur_half_bad(3)) / (num_sp(7:8) + num_half(3));
                    % num_sp(7:8) = num_sp(7:8) + num_half(3);
                    cost(i) = cost(i) - num_half(3) * half_crash(3);
                else
                    correct_sp(7:8) =  correct_sp(7:8) - num_half(3) * (1 - cur_half_bad(3));
                    total_sp(7:8) =  total_sp(7:8) - num_half(3);
                end
                num_sp = total_sp;
                cur_sp_bad = (num_sp - correct_sp) ./ num_sp;
            else
                next_round = 1;
            end

            % 丢了就结束
            if next_round == 1
                break
            end
            ini_sp_bad = cur_sp_bad;
            num_ini = num_sp;
            % cur_sp_bad = sp_bad_rate;
            % cur_half_bad = half_bad_rate;
            % cur_fin_bad = fin_bad_rate;

        end

        fitness(i)=cost(i);

    end

    [a,b]=max(fitness);
    [c,d]=max(cost);
    
    choosen_pop=zeros(pop,n);

    fit1=(fitness-min(fitness))/(max(fitness)-min(fitness));
    fit2=fit1/sum(fit1);
    fit3=cumsum(fit2);

    compare=sort(rand(pop,1));
    i=1;j=1;

    while i<=pop
        if compare(i)<fit3(j)
            choosen_pop(i,:)=initial_pop(j,:);
            i=i+1;
        else
            j=j+1;
        end
    end

    crossover_pop=choosen_pop;

    for i=1:2:pop-1
        if rand<crossover_prob
            % temp=crossover_pop(i, 8:12);
            % 
            % for k=1:length(temp)
            %     f(k)=find(crossover_pop(i+1, :)==temp(k));
            % end
            % 
            % f=sort(f);
            % 
            % for p=1:length(temp)
            %     crossover_pop(i, p+7)=crossover_pop(i+1,f(p));
            %     crossover_pop(i+1, f(p))=temp(p);
            % end
            idx = randperm(length(crossover_pop(i,:)), 20);
            temp = crossover_pop(i, idx);
            crossover_pop(i, idx) = crossover_pop(i+1, idx);
            crossover_pop(i+1, idx) = temp;

        end
    end

    % mutation_pop=crossover_pop;
    % 
    % for i=1:pop
    %     if rand<mutation_prob
    %         r=randperm(20);
    %         r1=r(1);
    %         r2=r(2);
    %         row=mutation_pop(i, :);
    %         m1=find(row==r1);
    %         m2=find(row==r2);
    %         mutation_pop(i, m1)=r2;
    %         mutation_pop(i, m2)=r1;
    %     end
    % end

    mutation_pop = crossover_pop;  % 初始化变异种群

%     for i = 1:pop
%         if rand < mutation_prob
%             mutation_idx = randi([1, 13]);
% 
%             if mutation_idx >= 1 && mutation_idx <= 8
%                 % 前 8 个位置是零配件检测 (0 或 1)
%                 mutation_pop(i, mutation_idx) = 1 - mutation_pop(i, mutation_idx);  % 0 和 1 互换
%     
%             elseif mutation_idx >= 9 && mutation_idx <= 11
%                 % 第 9 到 11 个位置是半成品检测 (0, 1, 2)
%                 current_value = mutation_pop(i, mutation_idx);
%                 new_value = randi([0, 2]);
%                 while new_value == current_value
%                     new_value = randi([0, 2]);
%                 end
%                 mutation_pop(i, mutation_idx) = new_value;
%     
%             elseif mutation_idx == 12
%                 % 第 12 个位置是成品检测 (0 或 1)
%                 mutation_pop(i, mutation_idx) = 1 - mutation_pop(i, mutation_idx);
%     
%             elseif mutation_idx == 13
%                 % 第 13 个位置是全部丢弃还是拆解 (0 或 1)
%                 mutation_pop(i, mutation_idx) = 1 - mutation_pop(i, mutation_idx);
%             end
%         end
for i = 1:pop
    if rand < mutation_prob
        num_mutations = randi([1, length(crossover_pop(i,:))]);  
        mutation_indices = randperm(length(crossover_pop(i,:)), num_mutations);  % 从260个位置中随机选取num_mutations个位置进行变异

        for mutation_idx = mutation_indices
            % 使用 mod 函数将 mutation_idx 映射到 [1, 13] 的范围
            mapped_idx = mod(mutation_idx - 1, 13) + 1;

            if mapped_idx >= 1 && mapped_idx <= 8
                % 对零配件检测 (0 或 1) 进行取余处理
                mutation_pop(i, mutation_idx) = 1 - mutation_pop(i, mutation_idx);  % 0 和 1 互换

            elseif mapped_idx >= 9 && mapped_idx <= 11
                % 对半成品检测 (0, 1, 2) 进行取余处理
                current_value = mutation_pop(i, mutation_idx);
                new_value = randi([0, 2]);
                while new_value == current_value
                    new_value = randi([0, 2]);
                end
                mutation_pop(i, mutation_idx) = new_value;

            elseif mapped_idx == 12
                % 对成品检测 (0 或 1) 进行取余处理
                mutation_pop(i, mutation_idx) = 1 - mutation_pop(i, mutation_idx);

            elseif mapped_idx == 13
                % 对全部丢弃还是拆解 (0 或 1) 进行取余处理
                mutation_pop(i, mutation_idx) = 1 - mutation_pop(i, mutation_idx);
            end
        end
    end
end



%     end


    mutation_pop(end, :)=initial_pop(b, :);
    best_de = initial_pop(b, :);
    
    best_cost(g)=cost(b);
    initial_pop=mutation_pop;
    waitbar(g/M, h, sprintf('Processing... %d%%', round(g/M*100)));
end
close(h); 
best_cost(g)

plot(1:M, best_cost, 'b-o', 'LineWidth', 2, 'MarkerSize', 1, 'MarkerFaceColor', 'b');

%title('Best Cost Over Iterations', 'FontSize', 16);
xlabel('迭代次数', 'FontSize', 14);
ylabel('最佳成本', 'FontSize', 14);



grid on;
grid minor;
legend('最佳成本', 'Location', 'Best');

set(gca, 'FontSize', 12); % 调整坐标轴字体大小


