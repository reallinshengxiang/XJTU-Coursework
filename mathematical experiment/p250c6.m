format long
clc;
clf;
t=[1,2,3,4,6.5,9,12];
u=[6.2,7.3,8.2,9.0,9.6,10.1,10.4];
t0=0.2:0.1:12.5;
lglr=lglrcz(t,u,t0);
laglr=lglrcz(t,u,7)
fdxx=interp1(t,u,t0);
fendxx=interp1(t,u,7)
scyt=interp1(t,u,t0,'spline');
scancyt=interp1(t,u,7,'spline')
plot(t,u,'*',t0,lglr,'r',t0,fdxx,'g',t0,scyt,'b')
legend('观测点','拉格朗日插值曲线','分段线性插值曲线','三次样条插值曲线')
