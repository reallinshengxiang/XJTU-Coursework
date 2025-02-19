x=-4:0.1:4;
y=x;
[mx,my]=meshgrid(x,y);
mz=mx.^2-my.^2;
ix=find(mx==2);
px=2*ones(1,length(ix));
py=my(ix);
pz=mz(ix);
subplot(1,2,1);
mesh(mx,my,mz);
hold on;
plot3(px,py',pz','m*');
subplot(1,2,2);
plot3(px,py',pz');
figure(2);
iy=find(my==1);
py=ones(1,length(iy));
px=mx(iy);
pz=mz(iy);
mesh(mx,my,mz);
hold on;
plot3(px',py,pz','m*');
figure(3);
x=-4:0.001:4;
z=-10:0.1:10;
[mmx,mmz]=meshgrid(x,z);
mmy=sqrt(mmx.^2-mmz);
iz=find(mmz==3);
pz=(3*ones(1,length(iz)))';
px=mmx(iz);
py=mmy(iz);
ss=find(px.^2-pz<0);
py(ss)=NaN;
mesh(mx,my,mz);
hold on;
plot3(px,py,pz,'m*');
plot3(px,-py,pz,'m*');