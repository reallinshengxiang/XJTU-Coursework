function f=ex10_15(x)
        f(1)=6*x(1)+8*x(2);
        f(2)=-200*x(1)-200*x(2);
        f(3)=-x(2);
        
% goal=[40 -800 -6];
% weight=[40 -800 -6];
% x0=[2 2];
% A=[6 8;0 -1];
% b=[40 -6];
% lb=zeros(2,1);
% options=optimset('MaxFunEvals',5000);  % ���ú������۵�������Ϊ5000��
% [x,fval,attainfactor,exitflag] =fgoalattain(@ex10_15,x0,goal,weight,A,b,[],[],lb,[],[],options)

