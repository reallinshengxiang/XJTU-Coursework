t1=0:0.1:2*pi;
r1=4*(1+cos(t));
t2=0:0.1:8*pi;
r2=exp(0.1*t2);
figure(1);
polar(t1,r1);
figure(2);
polar(t2,r2);