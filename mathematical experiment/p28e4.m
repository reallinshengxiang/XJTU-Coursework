a=[1,1];
n=1;
while n<300
     plot(a(1),a(2),'r.'); 
     hold on;
     axis([0,300,1,7]) 
     n=n+1;
     a=a+[1,1/n];
     pause(0.1);
end