function varargout=listbox2(varargin)

if nargin<=1 %创建GUI界面
if nargin==0
        initial_dir=pwd;
elseif nargin==1 & exist(varargin{1},'dir')
        initial_dir=varargin{1};
else
        errordlg('输入不合法','输入错误!')
return
end
%打开fig图形文件
    fig=openfig(mfilename,'reuse');
%创建一个句柄结构，传给Callback例程用，并存放该句柄结构
    handles=guihandles(fig);
    guidata(fig,handles);
%初始化列表框
    load_listbox(initial_dir,handles)
%作为第一个输出参数，返回图形句柄
if nargout>0
        varargout{1}=fig;
end

elseif ischar(varargin{1}) %激活下面的Callback例程
try
%所有的Callback函数最终都经由feval调用。
[varargout{1:nargout}]=feval(varargin{:});
catch
        disp(lasterr);
end
end

%打开列表框中的文件的Callback例程
function varargout=listbox1_Callback(h,eventdata,handles,varargin)
if strcmp(get (handles.figure1,'SelectionType'),'open')
    index_selected=get(handles.listbox1,'Value');
    file_list=get(handles.listbox1,'String');
    filename=file_list{index_selected};
if handles.is_dir(handles.sorted_index(index_selected))
        cd(filename)
        load_listbox(pwd,handles)
else
        [path,name,ext,ver]=fileparts(filename);
switch ext
case'.fig'
                guide(filename)
otherwise
try
                    open(filename)
catch
                    errordlg(lasterr,'file Type Error',modal')
end
end
end
end

%读取当前目录中的文件，并按文件名排序
function load_listbox(dir_path,handles)
cd(dir_path)
dir_struct=dir(dir_path);
[sorted_names,sorted_index]=sortrows({dir_struct.name}');
handles.file_names=sorted_names;
handles.is_dir=[dir_struct.isdir];
handles.sorted_index=[sorted_index];
guidata(handles.figure1,handles)
set(handles.listbox1,'string',handles.filename,'Value',1)
set(handles.text1,'String',pwd)
