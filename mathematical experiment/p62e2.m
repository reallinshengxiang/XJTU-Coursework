t=linspace(0,2*pi,1000);
a=input('a=');
x=a*cos(t).^3;
y=a*sin(t).^3;
comet(x,y);