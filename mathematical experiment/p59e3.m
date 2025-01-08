a=input('成绩a=');
n=length(a);
a1=0;  a2=0;  a3=0;  a4=0;  a5=0;
for i=1:n
   if a(i)>90
        a1=a1+1;
   elseif a(i)>=80
        a2=a2+1;
   elseif a(i)>=70
        a3=a3+1;
   elseif a(i)>=60
       a4=a4+1;
   else
       a5=a5+1;
    end
end
fprintf('60分以下：%d\n60~70分：%d\n70~80分：%d\n80~90分：%d\n90分以上:%d\n',a5,a4,a3,a2,a1);