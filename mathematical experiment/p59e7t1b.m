p=0;
for i=1:16
    a=100-6*i;
    for j=1:13
        b=80-6*j;
        for k=1:9
            c=60-6*k;
            d=a*b*c;           
            if d==200
              a
              b
              c
              p=p+1;
           end           
        end

    end
end
if p==0 
    fprintf('不可以\n')
end