function mat_feat(f_name)								%<1>
disp('����������')										%<2>
A=magic(4)							
N=8;								
n=size(f_name,2);					
ff_name=[f_name blanks(N-n)];	
if ff_name==['my_det' blanks(2)]
   disp('���� A ������ʽֵ = ')
elseif ff_name==['rank' blanks(4)]
   disp('���� A ���� = ')
elseif ff_name==['norm' blanks(4)]
   disp('���� A ��2-���� = ')
elseif ff_name==['cond' blanks(4)]
   disp('���� A �������� = ')
elseif ff_name==['eig' blanks(5)]
   disp('���� A ������ֵ = ')
elseif ff_name==['svd' blanks(5)]
   disp('���� A ������ֵ = ')
else
disp('�������ָ����߲��Ǳ������ļ����ܽ���ģ����Ǵ���ģ�')
end
d=feval(f_name,A);
disp(d)
