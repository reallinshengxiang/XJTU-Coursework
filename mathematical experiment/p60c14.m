theta=linspace(0,2*pi,100);
a=linspace(0,4*pi,100);
x0=[0,0];
y0=[0,0];
for i=1:100
x=a(i)+cos(theta);
y=1+sin(theta);
x0(i)=a(i)-sin(a(i));
y0(i)=1-cos(a(i));
plot(x,y,'r',x0(i),y0(i),'b*','linewidth',2,'markersize',8);
hold on
plot(x0,y0,'g','linewidth',3);
x1=0:14;
x2=zeros(1,15);
y1=zeros(1,15);
y2=linspace(0,3,15);
plot(x1,y1,'k',x2,y2,'k');
text(0.3,2.7,'Y')
text(14,-0.3,'X')
text(0,-0.3,'O')
axis off
hold off
axis equal  
end
    movie(m)