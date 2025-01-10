function spir_len = spirallength(d, n, lcolor)
%CIRCLE plot a circle of radius as r in the provided color and calculate its area
% d������������
%   n��������Ȧ��
%   lcolor����ͼ�ߵ���ɫ
%   spir_len���������ܳ�
% spirallength(d, n)��������ɫ��Ԥ�������������
% spirallength(d, n,lcolor)������lcolor��ɫ��Ԥ�������������
% spir_len = spirallength(d, n)�����������ߵ��ܳ���������ɫ���������
% spir_len = spirallength(d, n,lcolor)�����������ߵ��ܳ�������lcolor��ɫ���������
% ��д��2009.7.6���޸���2011.8.8			����Ա��01
if nargin > 3
    error('����������࣡');
elseif nargin == 2
    lcolor = 'b';
end
j = sqrt(-1);
phi = 0: pi/1000 : n*2*pi;
amp = 0: d/2000 : n*d;
spir = amp .* exp(j*phi);
if nargout == 1
    spir_len = sum(abs(diff(spir)));
    fill(real(spir), img(spir), lcolor)
elseif nargout == 0
    plot(spir,lcolor)
else
    error('����������࣡');
end
axis('square')
