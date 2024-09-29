p=0;
for i=1:50
    a=100-2*i;
    mianji=i*4800;
    for j=1:80
        b=80-j;
        mianji=mianji+j*a*60;
        for k=1:15
            c=60-4*k;
            d=a*b*c;           
            if d==200
              p=p+1; 
              mianji=mianji+k*a*b;
              cishu=i+j+k;
              fprintf('方案%d\n长的方向按2cm厚度切%d次 宽的方向按1cm厚度切%d次 高的方向按4cm厚度切%d次\n',p,i,j,k);
              fprintf('面积%d cm^2\n次数%d\n边长%d %d %d\n',mianji,cishu,a,b,c);
           end           
        end
    end
end
if p==0 
    fprintf('不可以\n')
end