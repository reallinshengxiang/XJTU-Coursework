x=1;
d=0.0000001;
while x>d
    x=x/10;
    y=(1/x)^sin(1/x);
    fprintf('x=%.8f y=%.8f\n',x,y);
end
x=0.1;
a=[x,(1/x)^sin(1/x)];
d=0.0001;
while x>0
    plot(a(1),a(2),'r.');
    axis([0,0.1,-1,10]) 
    x=x-d;
    y=(1/x)^sin(1/x);
    a=[x,y];
    pause(0.000000000000001);
    hold on;
end