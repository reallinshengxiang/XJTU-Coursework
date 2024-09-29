t=linspace(0,2*pi,100000);
x=4.*(sin(t)-sin(2*t)./2);
y=2.*(cos(t)-cos(t).^2);
comet(x,y);
