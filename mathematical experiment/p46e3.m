x=-2:0.01:2;
y=x;
[xb,yb]=meshgrid(x,y);
zb=(xb.^2+yb.^2)/2;
xx=find(xb.^2+yb.^2>2);
zb(xx)=NaN;
figure(1);
mesh(xb,yb,zb);

[x,y,z]=cylinder(1,1000)
x=x+1;
figure(2);
mesh(x,y,);
hold on;
x=-4:0.01:4;
y=x;
[xb,yb]=meshgrid(x,y);
zb=sqrt(xb.^2+yb.^2);
xx=find(xb.^2+yb.^2>2*xb);
zb(xx)=NaN;
mesh(xb,yb,zb);
axis equal;

x=-2:0.01:2;
y=x;
[xb,yb]=meshgrid(x,y);
xx=find(1-x-y<0);
zb(xx)=NaN;
figure(3);
mesh(xb,yb,zb);
hold on;
[x,y,z]=cylinder(1,1000)
y=y/2;
mesh(x,y,z);