x=-1:0.01:1;
y=sqrt(1-x.^2);
subplot(1,2,1);
plot(x,y)
axis equal
t=0:0.01:2*pi;
x=exp(i*t);
y=[x;2*x;3*x]';
subplot(1,2,2);
plot(y)
axis equal