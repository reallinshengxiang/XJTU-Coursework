x=0:pi/100:2*pi;
y1=2*exp(-0.5*x).*sin(2*pi*x);
y2=2*exp(-0.5*x);
y3=-2*exp(-0.5*x);
plot(x,y1,'m-',x,y2,'m--',x,y3,'m--');
axis([0,2*pi,-2,2]);
grid off;
xlabel('x轴')
ylabel('y轴')
title('函数曲线')
text(3,0.5,'\leftarrow y2=2*exp(-0.5*x)')
text(0.88,-0.88,'\leftarrow y1=2*exp(-0.5*x).*sin(2*pi*x)');
text(3,-0.45,'\leftarrow y3=-2*exp(-0.5*x)');