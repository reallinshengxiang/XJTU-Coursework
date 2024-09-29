x=-5:1:5;
y=x;
clc;
clf;
[xx,yy]=meshgrid(x,y);
qmgj=xlsread('qmgj.xls');
zz=qmgj;     
figure(1)
mesh(xx,yy,zz); 
figure(2)
xb=-5:0.25:5;     
yb=-5:0.25:5;
[xxb,yyb]=meshgrid(xb,yb);
zzb=interp2(xx,yy,zz,xxb,yyb,'cubic');
mesh(xxb,yyb,zzb) 
figure(3)
clc
x=-5:1:5;
y=-5:1:5;
[xx,yy]=meshgrid(x,y);
zz=qmgj;
p=[xx,yy,zz];
pp = alphaShape(p);
A = surfaceArea(pp);
disp(['表面积为 ',num2str(A)])

