function edit1_Callback(hObject, eventdata, handles)
% hObject :edit1����ľ�����μ�gcbo�÷���
% eventdata:Ϊ�˼���MATLAB�����汾�ı����ӿ�
% handles:ӵ�о����ȫ�ֱ������������������û����ݣ��μ� GUIDATA��
% get(hObject,'String')������edit1���������Ϊ�ı���ʽ
% str2double(get(hObject,'String'))����edit1���������ת��Ϊ˫������

%���ַ�������ʽ���洢�����ı���1�����ݡ�����ַ����������֣�����ʾ�հ�����
input = str2num(get(hObject,'String')); 
%��������Ƿ�Ϊ�ա����Ϊ�գ���Ĭ����ʾΪ0
if (isempty(input))     
set(hObject,'String','0')
end
guidata(hObject, handles);
