x=1;
d=0.000000001;
while x>d
    x=x/10;
    y=x^sin(x);
    fprintf('x=%.8f y=%.8f\n',x,y);
end
x=0.1;
a=[x,x^(2/log(x))];
d=0.0001;
while x>0
    plot(a(1),a(2),'r.');
    axis([0,0.1,0,3]) 
    x=x-d;
    y=x^sin(x);
    a=[x,y];
    hold on;
end