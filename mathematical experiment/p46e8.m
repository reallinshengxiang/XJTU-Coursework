m=100;
z=1.2*(-2*m:2*m)/m;
r=ones(size(z));
theta=(0:m)/m*2*pi;
x1=r'*cos(theta)+1;
y1=r'*sin(theta);
z1=z'*ones(1,1+m);
bb=find(x1.^2+y1.^2+z1.^2>4);
z1(bb)=NaN;
mesh(x1,y1,z1);
hold on
[x0,y0,z0]=sphere(100);
aa=find(((2*x0)-1).^2+(2*y0).^2>1);
z0(aa)=NaN;
mesh(2*x0,2*y0,2*z0)
axis equal;
axis on;
colormap(cool);