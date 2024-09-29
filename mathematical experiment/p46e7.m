x=-3:0.1:3;
y=-3:0.1:3;
[xb,yb]=meshgrid(x,y);
figure(1);
zb=(2*xb.^2-1.05*xb.^4+xb.^6)./(6-xb.*yb+yb.^2);
surfc(xb,yb,zb);

x=-1:0.01:1;
y=-1:0.01:1;
[xb,yb]=meshgrid(x,y);
figure(2);
zb=xb.^2+yb.^2-cos(18*x)-cos(18*y);
surfc(xb,yb,zb);