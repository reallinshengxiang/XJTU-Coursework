x=-2:0.1:2;
y=-2:0.1:2;
[xb,yb]=meshgrid(x,y);
zb=sin(xb.*yb);
figure(1);
mesh(xb,yb,zb);
figure(2);
surf(xb,yb,zb);
figure(3);
surfc(xb,yb,zb);