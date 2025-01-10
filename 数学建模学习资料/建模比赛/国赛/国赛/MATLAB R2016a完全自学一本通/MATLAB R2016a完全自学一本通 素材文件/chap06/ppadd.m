function p=ppadd(a,b)
%  ppadd: for polynomial addition.
%  ppadd(a,b) adds the polynomial a and b
%  2012.01.23
if nargin<2
     error(' Not enough input arguments ')  %  ȷ���������
end
a=a(:).' ;          %  ������ת��Ϊ������
b=b(:).' ;
na=length(a) ;       %  ����ӵ�������ʽ������
nb=length(b) ;
p=[zeros(1,nb-na) a]+[zeros(1,na-nb) b] ;     %  ��ӵ�������ʽ��������ʱ���ߴβ���
