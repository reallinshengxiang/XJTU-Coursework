xn=[1 (1+sqrt(3)*1i)/2 0 1];
n=5;
for n=1:n
    xp=xn;
    l=length(xn)-1;
    for k=0:l-1
        dx=(xp(k+2)-xp(k+1))/3;
        xn(4*k+1)=xp(k+1);
        xn(4*k+2)=xp(k+1)+dx;
        xn(4*k+3)=xn(4*k+2)+dx*(1/2-sqrt(3)*1i/2);
        xn(4*k+4)=xp(k+1)+2*dx;
    end
    xn(4*l+1)=xp(l+1);
end
plot(xn,'k-');
hold on;
axis equal;