x=2:1:11;
y=[58,50,44,38,34,30,29,26,25,24];
f=inline('a(1)+a(2)./x','a','x');
a=[0 0];
[a,resnorm]=lsqcurvefit(f,a,x,y);
plot(x,y,'*')
hold on
g=a(1)+a(2)./x;
plot(x,g,'r-');

resnorm
a