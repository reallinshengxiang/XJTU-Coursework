clc;
clf;
x=1:1:12;
y=[3.1 3.8 6.9 12.7 16.8 20.5 24.5 25.9 22 16.1 10.7 5.4];
f=inline('a(1)*cos(a(2)*x)+a(3)*sin(a(2)*x)+a(4)','a','x');
a=[0 0 0 0];
[a,resnorm]=lsqcurvefit(f,a,x,y);
plot(x,y,'*')
hold on
g=a(1)*cos(a(2)*x)+a(3)*sin(a(2)*x)+a(4);
plot(x,g,'r-');

resnorm
a