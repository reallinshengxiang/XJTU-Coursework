x=-2:0.1:2;
y=-2:0.1:2;
[xb,yb]=meshgrid(x,y);
zb=(xb.*yb)./(x.^2+y.^2);
figure(1);
surfc(xb,yb,zb);
hold on;
x=0;
y=0;
z=0;
plot3(x,y,z,'.');

x=-20:1:20;
y=-20:1:20;
[xb,yb]=meshgrid(x,y);
zb=(1+xb+yb).^2;
figure(2);
surfc(xb,yb,zb);

x=-20:1:20;
y=-20:1:20;
[xb,yb]=meshgrid(x,y);
zb=sqrt(xb.^2+yb.^2);
figure(3);
surfc(xb,yb,zb);

u=1:0.1:10;
t=0:pi/100:2*pi;
[ub,tb]=meshgrid(u,t);
x=ub.*cos(tb);
y=ub.*sin(tb);
z=sqrt(ub-1);
figure(4);
surf(x,y,z);
hold on;
z=-sqrt(ub-1);
surf(x,y,z);