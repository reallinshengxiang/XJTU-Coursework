function Positions = initialization(SearchAgents_no,dim,ub,lb)

Boundary_no = size(ub, 2);              % 边界数

% 以下代码用以确定单个优化参数或多个优化参数的初值

% 用户输入相同的边界数/单个待优化参数
if Boundary_no == 1
    Positions = rand(SearchAgents_no, dim).*(ub-lb)+lb;
end

% 用户输入不同的边界数/多个待优化参数
if Boundary_no>1
    for i=1:dim
        ub_i=ub(i);
        lb_i=lb(i);
        Positions(:,i)=rand(SearchAgents_no,1).*(ub_i-lb_i)+lb_i;
    end
end