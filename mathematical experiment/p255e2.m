clc;
clf;
format long
n=input('请输入n=');
x=linspace(-10,10,n);
y=1./(1+25*x.^2);
xx=linspace(-10,10,1000);
yy=1./(1+25*xx.^2);
t0=-10:0.1:10;
lglr=lglrcz(x,y,t0);
fdxx=interp1(x,y,t0);
scyt=interp1(x,y,t0,'spline');
plot(x,y,'*',xx,yy,'b',t0,lglr,'r',t0,fdxx,'g')
legend('观测点','原函数','拉格朗日插值曲线','分段线性插值曲线')