k=0
for a=1:10000
    s=0;
    for b=1:fix(a/2)
        if mod(a,b)==0
            s=s+b;
        end
    end
    if s==a
        s
        k=k+1;
    end
end
k