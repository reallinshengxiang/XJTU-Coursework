xdata=[5.8,10.8,15.0,22.8];
ydata=[8.8,22.5,36.5,68.7];
x0=[0,0,0];
[x,resnorm]=lsqcurvefit(@nihehanshu,x0,xdata,ydata);
plot(xdata,ydata,'*')
hold on
outx = 5.8:0.1:22.8;
g=x(1).*exp(outx)+x(2).*outx+x(3)*ones(1,length(outx));
plot(outx,g,'b-');
resnorm
x(1)=x(1)*10/log(10);
vpa(x(1),20)
x(2)
x(3)=x(3)*10;
x(3)
hold off