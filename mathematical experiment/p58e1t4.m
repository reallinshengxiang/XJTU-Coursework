k=0
for a=1:100000
    x=0;
    for b=1:fix(a/2)
        if mod(a,b)==0
            x=x+b;
        end
    end
    y=0;
    for m=1:fix(x/2)
          if mod(x,m)==0
            y=y+m;
          end
    end
    if y==a&a<x
        [a,x]
        k=k+1;
    end
end
k