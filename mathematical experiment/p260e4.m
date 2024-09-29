clc;
clf;
x=[58 108 150 228];
y=[88 225 365 687];
c=polyfit(x.^1.5,y,0)

clc;
clf;
figure(1);
f1=inline('a1(1)*x+a1(2)','a1','x');
a1=[0 0];
[a1,resnorm1]=lsqcurvefit(f1,a1,x,y);
plot(x,y,'*')
hold on
g=a1(1)*x+a1(2);
plot(x,g,'b-');

figure(2);
f2=inline('a2(1)*x.^2+a2(2)*x+a2(3)','a2','x');
a2=[0 0 0];
[a2,resnorm2]=lsqcurvefit(f2,a2,x,y);
plot(x,y,'*')
hold on
g=a2(1)*x.^2+a2(2)*x+a2(3);
plot(x,g,'b-');

figure(3);
f3=inline('a3(1)*x.^3+a3(2)*x.^2+a3(3)*x+a3(4)','a3','x');
a3=[0 0 0 0];
[a3,resnorm3]=lsqcurvefit(f3,a3,x,y);
plot(x,y,'*')
hold on
g=a3(1)*x.^3+a3(2)*x.^2+a3(3).*x+a3(4);
plot(x,g,'b-');

figure(4)
f4=inline('a4(1)*x.^4+a4(2)*x.^3+a4(3)*x.^2+a4(4)*x+a4(5)','a4','x');
a4=[0 0 0 0 0];
[a4,resnorm4]=lsqcurvefit(f4,a4,x,y);
plot(x,y,'*')
hold on
g=a4(1)*x.^4+a4(2)*x.^3+a4(3)*x.^2+a4(4)*x+a4(5);
plot(x,g,'b-');

resnorm1
a1
resnorm2
a2
resnorm3
a3
resnorm4
a4