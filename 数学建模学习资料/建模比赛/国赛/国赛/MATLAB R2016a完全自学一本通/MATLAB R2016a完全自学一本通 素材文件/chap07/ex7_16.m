sym x;
f1=sym('(x-1)^3')
collect(f1)
syms x y t;
f2=sym('x*cos(t)+y*sin(t)+(x^2+2*x*y+3*y^2)*t')
collect(f2,x)
collect(f2,y)