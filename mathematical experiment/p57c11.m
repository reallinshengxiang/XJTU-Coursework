function [m,s]=p57c11(x)
n=length(x);
m=sum(x)/n;
s=sqrt(sum((x-m).^2)/n);