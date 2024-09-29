x=0:0.1:1;
y=[3.1,3.27,3.81,4.5,5.18,6,7.05,8.56,9.69,11.25,13.17];
f=inline('a(1)*exp(x)+a(2)*x.^2+a(3)*x.^3','a','x');
a0=[0 0 0];
[a,resnorm]=lsqcurvefit(f,a0,x,y)
plot(x,y,'*')
hold on
g=a(1)*exp(x)+a(2)*x.^2+a(3)*x.^3;
plot(x,g,'r-')