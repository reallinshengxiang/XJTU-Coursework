function y=average(x)
[a,b]=size(x);						 % �ж��������Ĵ�С
if~((a==1)|(b==1))| ((a==1)& (b==1))  % �ж������Ƿ�Ϊ����
    error('��������������')
end
y=sum(x)/length(x); 				%��������x����Ԫ�ص�ƽ��ֵ
