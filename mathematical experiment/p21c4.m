x=0:0.1:4*pi;
y1=0.2*exp(0.1*x).*sin(0.5*x);
y2=0.2*exp(0.1*x).*cos(0.5*x);
plot(x,y1,'-',x,y2)