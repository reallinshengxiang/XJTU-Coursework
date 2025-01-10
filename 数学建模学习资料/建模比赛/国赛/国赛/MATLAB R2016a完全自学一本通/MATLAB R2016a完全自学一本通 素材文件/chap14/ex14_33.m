clear;
fs=1200;     %����Ƶ��
N=300;     % N/fs������
n=0:N-1;
t=n/fs;     %ʱ��
fL=20; 
fH=200;    
s= cos(2*pi*fL*t)+ cos(2*pi*fH*t);
subplot(121);plot(t,s);
title('�����ź�'); xlabel('t/s');ylabel('����');
sfft=fft(s);
subplot(122);
plot((1:length(sfft)/2)*fs/ length(sfft),2*abs(sfft(1:length(sfft)/2))/ length(sfft));
title('�ź�Ƶ��'); xlabel('Ƶ��/Hz');ylabel('����');
%��Ƶ�ͨ�˲�����
Wp = 50/fs; Ws = 100/fs;    		%��ֹƵ��50Hz,�����ֹƵ��100Hz,����Ƶ��200Hz
[n,Wn] = buttord(Wp,Ws,1,50);  	%���˥������50db,ͨ���Ʋ�С��1db
%����õ�Butterworth��ͨ�˲�������С����N��3dB��ֹƵ��Wn
[a,b]=butter(n,Wn);     			%���Butterworth��ͨ�˲���
[h,f]=freqz(a,b,'whole',fs);        	%�����ֵ�ͨ�˲�����Ƶ����Ӧ
f=(0:length(f)-1)'*fs/length(f);    	%���ж�Ӧ��Ƶ��ת��
figure(2);
plot(f(1:length(f)/2),abs(h(1:length(f)/2)));     	%����Butterworth��ͨ�˲����ķ�Ƶ��Ӧͼ
title('���ϵ�ͨ�˲���'); xlabel('Ƶ��/Hz'); ylabel('����');
grid;
sF=filter(a,b,s);      				%���Ӻ���s������ͨ�˲����Ժ���º���
figure(3);
subplot(121);
plot(t,sF);     					%���Ƶ��Ӻ���S������ͨ�˲����Ժ��ʱ��ͼ��
title('����ź�');xlabel('t/s');ylabel('����');
SF=fft(sF);  
subplot(122);
plot((1:length(SF)/2)*fs/ length(SF),2*abs(SF(1:length(SF)/2))/ length(SF));
title('��ͨ�˲����Ƶ��ͼ'); xlabel('Ƶ��/Hz');ylabel('����');
