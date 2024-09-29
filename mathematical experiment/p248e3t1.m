x=2:1:11;
y=[58,50,44,38,34,30,29,26,25,24];
f1=inline('a1(1)*x+a1(2)','a1','x');
a1=[0 0];
[a1,resnorm1]=lsqcurvefit(f1,a1,x,y);
plot(x,y,'*')
hold on
g1=a1(1)*x+a1(2);
plot(x,g1,'r-');

f2=inline('a2(1)*x.^2+a2(2)*x+a2(3)','a2','x');
a2=[0 0 0];
[a2,resnorm2]=lsqcurvefit(f2,a2,x,y);
plot(x,y,'*')
hold on
g2=a2(1)*x.^2+a2(2)*x+a2(3);
plot(x,g2,'b-');

f3=inline('a3(1)*x.^3+a3(2)*x.^2+a3(3)*x+a3(4)','a3','x');
a3=[0 0 0 0];
[a3,resnorm3]=lsqcurvefit(f3,a3,x,y);
plot(x,y,'*')
hold on
g3=a3(1)*x.^3+a3(2)*x.^2+a3(3)*x+a3(4);
plot(x,g3,'g-');

resnorm1
resnorm2
resnorm3

