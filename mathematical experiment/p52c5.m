y=[];
for x=-1:0.1:2
    if x>=-1&x<0
        y=[y,x+1];
        if x==-1
            f1=x+1
        end
    elseif x>=0&x<1
        y=[y,1];
       if x==0.5
            f2=1
        end
    else
        y=[y,x^2];
        if x==1.5
            f3=x^2
        end
    end
end
x=-1:0.1:2;
plot(x,y);