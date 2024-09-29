function f=jiecheng(n)
if n<=1
    f=1;
else
    f=jiecheng(n-1)*n;
end
