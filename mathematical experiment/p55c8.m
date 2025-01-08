clear;
clf;
hold on
axis([0,150,2,2.8]);
grid 
for n=2:2:150
    an=(1+1/n)^n;
    plot(n,an,'r.','markersize',15);
    pause(0.1);
    fprintf('n=%d an=%.4f\n',n,an);
end