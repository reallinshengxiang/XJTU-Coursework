x=linspace(-5,10,1000);
y=exp(x);
plot(x,y);
hold on;
y1=x+1;
plot(x,y1);
hold on;
y2=1+x+x.^2/2;
plot(x,y2);
hold on;
y3=1+x+x.^2/2+x.^3/6;
plot(x,y3);
hold on;
y4=1+x+x.^2/2+x.^3/6+x.^4/24;
plot(x,y4);
hold on;
y5=1+x+x.^2/2+x.^3/6+x.^4/24+x.^5/120;
plot(x,y5);
hold on;
y6=1+x+x.^2/2+x.^3/6+x.^4/24+x.^5/120+x.^6/720;
plot(x,y6);
hold on;
y7=1+x+x.^2/2+x.^3/6+x.^4/24+x.^5/120+x.^6/720+x.^7/5040;
plot(x,y7);
hold on;
y8=1+x+x.^2/2+x.^3/6+x.^4/24+x.^5/120+x.^6/720+x.^7/5040+x.^8/40320;
plot(x,y8);
hold on;
y9=1+x+x.^2/2+x.^3/6+x.^4/24+x.^5/120+x.^6/720+x.^7/5040+x.^8/40320+x.^9/362880;
plot(x,y9);
hold on;
y10=1+x+x.^2/2+x.^3/6+x.^4/24+x.^5/120+x.^6/720+x.^7/5040+x.^8/40320+x.^9/362880+x.^10/3628800;
plot(x,y10);