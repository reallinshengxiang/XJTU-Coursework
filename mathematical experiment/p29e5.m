t=linspace(0,2*pi,100);
a=input('Please input a=');
x=2*a*sin(t).^2;
y=2*a*sin(t).^2.*tan(t);
figure(1);
plot(x,y);

t=linspace(0,100,300);
x=3*a*t./(1+t.^3);
y=3*a*t.^2./(1+t.^3);
figure(2);
plot(x,y);

x=-100:0.1:100;
y=x.^(2/3);
figure(3);
plot(x,y);

y=linspace(-1,1,100);
x=log(1+sqrt(1-y.^2)./y)-sqrt(1-y.^2);
figure(4);
plot(x,y,'b');
hold on;
x=log(1-sqrt(1-y.^2)./y)+sqrt(1-y.^2);
plot(x,y,'b');