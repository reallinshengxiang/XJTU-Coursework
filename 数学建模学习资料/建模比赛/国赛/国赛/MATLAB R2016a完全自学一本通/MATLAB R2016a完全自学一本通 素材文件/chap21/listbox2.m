function varargout=listbox2(varargin)

if nargin<=1 %����GUI����
if nargin==0
        initial_dir=pwd;
elseif nargin==1 & exist(varargin{1},'dir')
        initial_dir=varargin{1};
else
        errordlg('���벻�Ϸ�','�������!')
return
end
%��figͼ���ļ�
    fig=openfig(mfilename,'reuse');
%����һ������ṹ������Callback�����ã�����Ÿþ���ṹ
    handles=guihandles(fig);
    guidata(fig,handles);
%��ʼ���б��
    load_listbox(initial_dir,handles)
%��Ϊ��һ���������������ͼ�ξ��
if nargout>0
        varargout{1}=fig;
end

elseif ischar(varargin{1}) %���������Callback����
try
%���е�Callback�������ն�����feval���á�
[varargout{1:nargout}]=feval(varargin{:});
catch
        disp(lasterr);
end
end

%���б���е��ļ���Callback����
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

%��ȡ��ǰĿ¼�е��ļ��������ļ�������
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
