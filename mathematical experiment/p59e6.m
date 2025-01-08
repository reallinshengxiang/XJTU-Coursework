fplot(@(x)cos(x).*exp(2.*sin(x))-sin(x).*exp(2.*cos(x)),[-10,10]);
hold on;
fplot('0',[-10,10]);
for x=-10.01:0.001:9.99
    y=cos(x).*exp(2.*sin(x))-sin(x).*exp(2.*cos(x));
    x=x+0.001;
    y1=cos(x).*exp(2.*sin(x))-sin(x).*exp(2.*cos(x));
    x=x+0.001;
    y2=cos(x).*exp(2.*sin(x))-sin(x).*exp(2.*cos(x));
    x=x-0.002;
    if y<y1&y1>y2
        fprintf('极大值%.3f\n',x+0.001);
    elseif y>y1&y1<y2   
        fprintf('极小值%.2f\n',x+0.001);
    end
end
for t=6:0.001:7
    for x=-10:0.01:10
        y=cos(x).*exp(2.*sin(x))-sin(x).*exp(2.*cos(x));
        x=x+t;
        y1=cos(x).*exp(2.*sin(x))-sin(x).*exp(2.*cos(x));
        x=x-t;
        if fix(y*1000)~=fix(y1*1000)
            break;
        else 
            fprintf('周期%.3f\n',t);
        end
    end
end