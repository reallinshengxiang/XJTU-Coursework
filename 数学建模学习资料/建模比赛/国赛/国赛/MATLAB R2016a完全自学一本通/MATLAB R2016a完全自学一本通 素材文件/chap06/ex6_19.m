clear all;
[X,Y] = meshgrid(-3:.25:3);  %������֪��������դ���
Z = peaks(X,Y);         %������֪��ĺ���ֵ
[XI,YI] = meshgrid(-3:.125:3);   %���������ܵĲ�ֵ��
ZI = interp2(X,Y,Z,XI,YI);     
mesh(X,Y,Z), hold, mesh(XI,YI,ZI+15)
hold off
axis([-3 3 -3 3 -5 20])
