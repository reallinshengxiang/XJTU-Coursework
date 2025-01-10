function edit1_Callback(hObject, eventdata, handles)
% hObject :edit1对象的句柄（参见gcbo用法）
% eventdata:为了兼容MATLAB将来版本的保留接口
% handles:拥有句柄的全局变量，可以用来传输用户数据（参见 GUIDATA）
% get(hObject,'String')：返回edit1对象的内容为文本形式
% str2double(get(hObject,'String'))：将edit1对象的内容转化为双精度型

%以字符串的形式来存储数据文本框1的内容。如果字符串不是数字，则显示空白内容
input = str2num(get(hObject,'String')); 
%检查输入是否为空。如果为空，则默认显示为0
if (isempty(input))     
set(hObject,'String','0')
end
guidata(hObject, handles);
