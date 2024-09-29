syms xx
x=2;
for n=1:100
  x=x*(2*n+1)*(2*n+2)
  if 1/x<=0.001
      break;
  end
end
n*2+2
y1=taylor(cos(xx),'order',n*2+3)
subs(y1,xx,1)