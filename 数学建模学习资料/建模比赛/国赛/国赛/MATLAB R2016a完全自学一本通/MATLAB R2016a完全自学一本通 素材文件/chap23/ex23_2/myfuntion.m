function [m,n,p]=myfuntion(A)
m=sum(sum(A>2));
n=sum(sum(A<2));
p=sum(sum(A==2));
disp('����2�ĸ���')
disp(m)
disp('С��2�ĸ���')
disp(n)
disp('����2�ĸ���')
disp(p)
