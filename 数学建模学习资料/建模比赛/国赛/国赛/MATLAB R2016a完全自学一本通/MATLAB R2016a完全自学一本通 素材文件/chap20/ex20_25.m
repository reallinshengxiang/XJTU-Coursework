%����ͼ��
x = -2*pi:pi/12:2*pi;
y = x.^2;
subplot(2,2,1:2)
plot(x,y)
h1=subplot(223);
y = x.^4;
plot(x,y)
h2=subplot(224);
y = x.^5;
plot(x,y)
%����ע�;��ο��λ�úʹ�С
p1 = get(h1,'Position'); 
t1 = get(h1,'TightInset');
p2 = get(h2,'Position');
t2 = get(h2,'TightInset');
x1 = p1(1)-t1(1); y1 = p1(2)-t1(2); 
x2 = p2(1)-t2(1); y2 = p2(2)-t2(2); 
w = x2-x1+t1(1)+p2(3)+t2(3); h = p2(4)+t2(2)+t2(4);
%����ע�;��ο�
annotation('rectangle',[x1,y1,w,h],...
 'FaceAlpha',.2,'FaceColor','red','EdgeColor','red');
