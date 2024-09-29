clc;
clf;
x=1790:10:1980;
y=[3.9,5.3,7.2,9.6,12.9,17.1,23.2,31.4,38.6,50.2,62.9,76,92,105.7,122.8,131.7,150.7,179.3,203.2,226.5];
f1=inline('a1(1)*x+a1(2)','a1','x');
a1=[0 0];
[a1,resnorm1]=lsqcurvefit(f1,a1,x,y);
plot(x,y,'*')
hold on
g=a1(1)*x+a1(2);
plot(x,g,'r-');

f2=inline('a2(1)*x.^2+a2(2)*x+a2(3)','a2','x');
a2=[0 0 0];
[a2,resnorm2]=lsqcurvefit(f2,a2,x,y);
plot(x,y,'*')
hold on
g=a2(1)*x.^2+a2(2)*x+a2(3);
plot(x,g,'y-');

f3=inline('a3(1)*x.^3+a3(2)*x.^2+a3(3).*x+a3(4)','a3','x');
a3=[0 0 0 0];
[a3,resnorm3]=lsqcurvefit(f3,a3,x,y);
plot(x,y,'*')
hold on
g=a3(1)*x.^3+a3(2)*x.^2+a3(3).*x+a3(4);
plot(x,g,'b-');


f4=inline('exp(a4(1)+a4(2)*x)','a4','x');
a4=[0 0];
[a4,resnorm4]=lsqcurvefit(f4,a4,x,y);
plot(x,y,'*')
hold on
g=exp(a4(1)+a4(2)*x);
plot(x,g,'g-');


f5=inline('1./(1/450+exp(a5(1)*x+a5(2)))','a5','x');
a5=[0 0];
[a5,resnorm5]=lsqcurvefit(f5,a5,x,y);
plot(x,y,'*')
hold on
g=1./(1/450+exp(a5(1)*x+a5(2)));
plot(x,g,'m-');

resnorm1
a1
resnorm2
a2
resnorm3
a3
resnorm4
a4
resnorm5
a5

xx=2000:5:2020;
yy1=[0 0 0 0 0];
yy1=a1(1)*xx+a1(2)

xx=2000:5:2020;
yy2=[0 0 0 0 0]; 
yy2=a2(1)*xx.^2+a2(2)*xx+a2(3);

xx=2000:5:2020;
yy3=[0 0 0 0 0]; 
yy3=a3(1)*xx.^3+a3(2)*xx.^2+a3(3).*xx+a3(4)

xx=2000:5:2020;
yy4=[0 0 0 0 0]; 
yy4=exp(a4(1)+a4(2)*xx)

xx=2000:5:2020;
yy5=[0 0 0 0 0]; 
yy5=1./(1/450+exp(a5(1)*xx+a5(2)))