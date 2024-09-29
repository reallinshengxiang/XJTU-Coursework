k=0;
A=[0,2]; 
B=[0,exp(1)];
d=1; 
while d>0.01
 plot(A(1),A(2),'r.'); 
 hold on
 plot(B(1),B(2),'b.');
 axis([0,135,2,3]) 
 pause(0.1);
 k=k+1;
 B=B+[1,0]; 
 A=[k,(1+1/k)^k]; 
 d=exp(1)-(1+1/k)^k;
end