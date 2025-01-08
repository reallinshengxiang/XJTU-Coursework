function n=isprime(x)
n=1;
for i=2:sqrt(x)
   if mod(x,i)==0
       n=0;
       break;
      end
    end
if x==2
    n=1;
end