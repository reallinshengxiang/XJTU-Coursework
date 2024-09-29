n=0;
for m=100:1000
    k=1;
    i=2;
    while i<=sqrt(m)
        if mod(m,i)==0
            k=0;
            break;
        end
        i=i+1;
    end
    if k==1
        n=n+1;
        prime(n)=m;
    end
end
prime