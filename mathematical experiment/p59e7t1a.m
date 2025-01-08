p=0;
for i=1:20
    a=100-5*i;
    for j=1:16
        b=80-5*j;
        for k=1:7
            c=60-8*k;
            d=a*b*c;           
            if d==200
              p=p+1;
              fprintf('方案%d\n长的方向按5cm厚度切%d次\n宽的方向按5cm厚度切%d次\n高的方向按8cm厚度切%d次\n',p,i,j,k);
           end           
        end
    end
end
if p==0 
    fprintf('不可以\n')
end