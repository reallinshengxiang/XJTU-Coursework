import pandas as pd
import os
import matplotlib.pyplot as plt
from pandas_visual_analysis import VisualAnalysis


def data_read(data_path, file_name):
    df = pd.read_csv(os.path.join(data_path, file_name), header=None)
    # df = pd.read_csv(os.path.join(data_path, file_name), delim_whitespace=True, header=None, skiprows=1) 
    # print(df)
    ##变量重命名 (Variable renaming)
    columns = ["X1","X2","X3","X4","X5","X6","X7","X8","X9","X10","X11","X12","X13","X14","X15","X16","X17","X18","X19","X20","X21","X22","X23","X24","target"]
    df.columns = columns
    for col in df.columns:
        if col != 'target':
            df[col] = df[col].astype(int) 
    ##将标签变量由状态1,2转为0,1;0表示好用户，1表示坏用户 (Convert label variable from states 1,2 to 0,1; 0 represents good users, 1 represents bad users)
    # df.target = df.target - 1
    return df

def category_continue_separation(df,feature_names):
    categorical_var = []
    # numerical_var = []
    if 'target' in feature_names:
        feature_names.remove('target')
    ##先判断类型，如果是int或float就直接作为连续变量
    columns_to_sum = ["X8", "X16", "X5", "X2", "X18", "X11", "X13"]

    numerical_var = []  # 初始化一个空列表

    for col in columns_to_sum:
        numerical_var.extend(df[col].values) 
    # numerical_var = list(df[feature_names].select_dtypes(include=['int','float','int32','float32','int64','float64']).columns.values)
    categorical_var = [x for x in feature_names if x not in numerical_var]
    return categorical_var,numerical_var

def data_analysis_plot_num(numerical_var, df, start, mid, row, col, showlabel=False):
    p = 1
    plt.figure(figsize=(20,18))
    for i in numerical_var[start:mid]:
        df_var = "df_" + i
        df_var = pd.DataFrame({'target':df["target"],'variables':df[i]})
        # print("")
        # print(df_var)
        
        df_var_good = df_var.loc[df_var["target"]==0,]
        df_var_good = df_var_good.sort_values(["variables"]) #排序
        # print("")
        # print(df_var_good)

        df_var_bad = df_var.loc[df_var["target"]==1,]
        df_var_bad = df_var_bad.sort_values(["variables"]) #排序
        # print("")
        # print(df_var_bad)
        
        plt.subplot(row,col,p) #子区空间为2行3列 
        if i == "period" or i == "age":
            bins_i = 60
        elif i == "credit_limit":
            bins_i = 150
        else:
            bins_i = 50
        plt.hist(df_var_good["variables"],bins=bins_i,color='r',alpha=0.5,rwidth=0.6,density=True,label='好用户')
        plt.hist(df_var_bad['variables'],bins=bins_i,color='b',alpha=0.5,rwidth=0.6,density=True,label='坏用户')
        plt.legend()
        if p == 1:
            plt.title('好坏用户分布直方图')
        plt.xlabel(i)
        plt.ylabel('count')

        p = p+1

    plt.show()

def data_analysis_plot(categorical_var, df, start, mid, row, col, showlabel=False):
    p = 1
    plt.figure(figsize=(20,18))
    for i in categorical_var[start:mid]:
        df_var = "df_" + i
        df_var = pd.crosstab(df[i],df["target"])
        # print(df_var)
        # VisualAnalysis(df_var)
        df_var["bad_rate"] = round(df_var[1]/(df_var[1]+df_var[0]),4)
        # print('df_var', df_var)
        # print(df_var.index)
        # print(df_var.columns)
        # print(p)

        #添加子区间绘制，
        ax1 = plt.subplot(row,col,p) #子区空间为n行n列 

        year = df_var.index # 横坐标
        data1 = df_var[0] # 纵坐标 好用户
        data2 = df_var[1] # 纵坐标 坏用户
        data3 = df_var["bad_rate"]

        # print(df_var)

        # 先得到year长度, 再得到下标组成列表
        x = range(len(year))
        bar_width = 0.3

        # 好坏用户柱状图
        ax1.bar(x, data1, width=bar_width, color='#3A669C', label="好用户")
        # 向右移动0.2, 柱状条宽度为0.2
        ax1.bar([i + bar_width for i in x], data2, width=bar_width, color='#C0504D',label="违约用户")

        # 底部汉字移动到两个柱状条中间(本来汉字是在左边蓝色柱状条下面, 向右移动0.1)
        plt.xticks([i + bar_width/2 for i in x], year)
        if p == 1 or p == col+1:
            ax1.set_ylabel('用户数量',size=10)
        ax1.set_xlabel(i,size=10)

        text_heiht = 3
        # 为每个条形图添加数值标签
        for x1,y1 in enumerate(data1):
            ax1.text(x1, y1+text_heiht, y1,ha='center',fontsize=8)
        for x2,y2 in enumerate(data2):
            ax1.text(x2+bar_width,y2+text_heiht,y2,ha='center',fontsize=8)

        # bad_rate线 共用纵坐标轴
        ax2 = ax1.twinx()
        p3 = ax2.plot([i + bar_width/2 for i in x], data3, color="gray",linestyle='--', label="坏用户占比")
        
        if p == 3 or p == 6:
            ax2.set_ylabel("坏用户占比")

        if p == 1 and showlabel == True:
            ax1.legend(loc="upper center")
            ax2.legend(loc=2)
        
        p = p + 1

    plt.show()

# Example usage with corrected paths and file names
df1 = data_read("D:\\shumuolearing\\jiangyou\\data", "Ger.csv")  # Adjust file extension as necessary
# df2 = data_read("D:\\shumuolearing\\jiangyou\\data", "Aus.csv")  # Adjust file extension as necessary
(categorical_var, numerical_var) = category_continue_separation(df1,["X1","X2","X3","X4","X5","X6","X7","X8","X9","X10","X11","X12","X13","X14","X15","X16","X17","X18","X19","X20","X21","X22","X23","X24","target"])
data_analysis_plot(categorical_var, df1, 1, 13, 4, 4, showlabel=False)

print(df1.describe())

data_analysis_plot_num(categorical_var, df1, 0, 7, 4, 2, showlabel=False)