for a=1:100
  c=0;
  x=a;
  while x>=10
     b=mod(x,10);
     x=fix(x/10);
     c=10*c+b;
  end
  c=10*c+x;
  A=a+c;
  B=0;
  y=A;
  while y>=10
      C=mod(y,10);
      y=fix(y/10);
      B=10*B+C;
  end
  B=10*B+y;
  k=1;
  while B~=A
      k=k+1;
      A=A+B;
      m=0;
      z=A;
      while z>=10
          n=mod(z,10);
          z=fix(z/10);
          m=10*m+n;
      end
      m=10*m+z;
      B=m;
  end
      [a,A]
end