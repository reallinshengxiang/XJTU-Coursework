clc;
clf;
x=[0.6,1.3,1.6,2.3,2.4,2.7,3,3.6,4.1,4.9];
y=[4,13.1,17.7,34.5,36.9,49,65,110.8,189.4,409.1];
f=inline('a(1)*exp(x)+a(2)*sin(x)+a(3)*log(x)','a','x');
a0=[0 0 0];
[a,resnorm]=lsqcurvefit(f,a0,x,y)
plot(x,y,'*')
hold on
g=a(1)*exp(x)+a(2)*sin(x)+a(3)*log(x);
plot(x,g,'r-')