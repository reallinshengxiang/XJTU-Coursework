n=input('请输入n=');
p=1;
sum=1;
for i=1:n
    p=p*i;
    sum=sum+1/p;
    fprintf('i=%.0f,p=%.8f,e=%.8f\n',i,p,sum);
end