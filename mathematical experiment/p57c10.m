function Fn=p57c10(n);
if n==1
    Fn=1;
elseif n==2
    Fn=[1,1];
else
    a=p57c10(n-1);
    Fn=[a,a(end-1)+a(end)];
end