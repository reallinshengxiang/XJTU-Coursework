k=0;
for i=100:999
    if rem(i,10).^3+rem(fix(i/10),10).^3+fix(i/100).^3==i
        k=k+1;
        sxh(k)=i;
    end
end
sxh