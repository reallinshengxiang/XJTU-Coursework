from tkinter import *
import time
import os

window_minsize = 400                 # 窗体最小大小
go_row = 18                          # 棋盘最大行数（本程序默认第一行为0，故共有19行）
go_column = 18                       # 棋盘最大列数（本程序默认第一列为0，故共有19列）
go_boundary = 25                     # 棋盘边界空出的空间大小
go_width = 2                         # 棋盘绘制的线条粗细
go_dot = 10                          # 棋子的大小

root = Tk()
canvas = Canvas(root)


def go_printline(pos1, pos2):         # 画一条线
    canvas.create_line((pos1[0]+go_boundary, pos1[1]+go_boundary), (pos2[0]+go_boundary,pos2[1]+go_boundary), width=go_width)
    # 由于本程序需实现窗口大小的调节，故直线的起始位置和结束位置是动态的，无法通过简单的定值实现

def canvas_print():                   # 画棋盘主体
    [w, h] = [canvas.winfo_reqwidth()-go_boundary*2,canvas.winfo_reqheight()-go_boundary*2]
    go_printline((0, 0), (w, 0))
    go_printline((0, 0), (0, h))
    go_printline((w, 0), (w, h))
    go_printline((0, h), (w, h))
    for i in range(1, go_row):
        go_printline((1.0*w/go_row*i, 0), (1.0*w/go_row*i, h))
    for i in range(1, go_column):
        go_printline((0, 1.0*h/go_column*i), (w, 1.0*h/go_column*i))
    for i in range(go_row+1):
        for j in range(go_column+1):
            if arr[i][j] == 1:
                [w, h] = [canvas.winfo_reqwidth()-go_boundary*2,canvas.winfo_reqheight()-go_boundary*2]
                [printx, printy] = [1.0*i*w/go_row+go_boundary,1.0*j*h/go_column+go_boundary]
                dot_size = 1.0*go_dot*w/400
                canvas.create_oval(printx-dot_size,printy-dot_size, printx+dot_size,printy+dot_size, outline="black", fill="black")
            elif arr[i][j] == 2:
                [w, h] = [canvas.winfo_reqwidth()-go_boundary*2,canvas.winfo_reqheight()-go_boundary*2]
                [printx, printy] = [1.0*i*w/go_row+go_boundary,1.0*j*h/go_column+go_boundary]
                dot_size = 1.0*go_dot*w/400
                canvas.create_oval(printx-dot_size,printy-dot_size, printx+dot_size,printy+dot_size, outline="black", fill="white")

last_resize = -1.0
def canvas_resize(event):     # 改变窗体大小时重绘棋盘
    global last_resize
    current_time = time.time()
    if (current_time-last_resize > 0.1):              #通过每次鼠标点击时重新绘制棋盘，实现该函数目的
        last_resize = current_time
        due = min(event.width, event.height)          #棋盘有最小标准
        canvas.configure(width=due, height=due)
        canvas.delete("all")
        canvas_print()


def canvas_dot(event):      # 移动鼠标时实时绘制棋子备选位置
    [w, h] = [canvas.winfo_reqwidth()-go_boundary*2,canvas.winfo_reqheight()-go_boundary*2]
    [x, y] = [event.x-go_boundary, event.y-go_boundary]
    [pos1, pos2] = [int(min(1.0*x/w*go_row, go_row)+0.5),int(min(1.0*y/h*go_column, go_column)+0.5)]
    [printx, printy] = [1.0*pos1*w/go_row+go_boundary,1.0*pos2*h/go_column+go_boundary]
    canvas.delete("dot")
    dot_size = 1.0*go_dot*w/400
    assert isinstance(printy, object)
    canvas.create_oval(printx-dot_size,printy-dot_size,printx+dot_size,printy+dot_size, outline="black", fill="", tag="dot")


arr = []
for i in range(go_row+1):
    tmp = []
    for j in range(go_column+1):
        tmp.append(0)
    arr.append(tmp)       #arr可看作一个二维数组，存储每个点上的棋子信息，0表示还没有落过子无字，
                          #1表示此处有黑子，2表示此处有白子，3表示此处原是黑子但现在被白子占领，4表示此处原是白子但现在被黑子占领
step=0             # 记录已下的棋子个数（其奇偶性表示当前棋子的颜色，奇为白，偶为黑）
ff=0
dx=[0,0,1,-1]
dy=[1,-1,0,0]
last_time1=0       #上一枚棋子落子时间
current_time1=0    #当前棋子落子时间

def canvas_go(event):
    global step,ff,last_time1,current_time1
    ff=0
    current_time1 = time.time()
    last_time1
    if current_time1-last_time1>=60 and step!=0:
        if step%2==1:
            print("执白子者超时")
            print("执黑子者胜利")
        else:
            print("执黑子者超时")
            print("执白子者胜利")
        last_time1 = current_time1;
    else:
        last_time1=current_time1;
        #print("不超时")

    [w, h] = [canvas.winfo_reqwidth() - go_boundary * 2, canvas.winfo_reqheight() - go_boundary * 2]
    [x, y] = [event.x - go_boundary, event.y - go_boundary]
    [pos1, pos2] = [int(min(1.0 * x / w * go_row, go_row) + 0.5), int(min(1.0 * y / h * go_column, go_column) + 0.5)]
    if arr[pos1][pos2]==3 and step%2==0:
        ff=1
    if arr[pos1][pos2]==0:
        ff=1
    if arr[pos1][pos2]==4 and step%2==1:
        ff=1
    if ff==1:
        if step%2==0 :
            arr[pos1][pos2]=1
        else:
            arr[pos1][pos2]=2
        [printx, printy] = [1.0*pos1*w/go_row+go_boundary,1.0*pos2*h/go_column+go_boundary]
        dot_size = 1.0*go_dot*w/400
        step=step+1
        if step%2:
            canvas.create_oval(printx-dot_size,printy-dot_size,printx+dot_size,printy+dot_size,outline="black",fill="black")
        else:
            canvas.create_oval(printx-dot_size,printy-dot_size,printx+dot_size,printy+dot_size,outline="black",fill="white")
        for i in range(go_row + 1):
            for j in range(go_column + 1):
                if arr[i][j]==1 or arr[i][j]==2:
                    que = [ ]
                    for ii in range(5000):
                        tmp=[]
                        for jj in range(5):
                            tmp.append(0)
                        que.append(tmp)
                    vis = [ ]
                    for ii in range(50):
                        tmp=[]
                        for jj in range(50):
                            tmp.append(0)
                        vis.append(tmp)
                    head=tail=1
                    que[head][1]=i
                    que[head][2]=j
                    m=arr[i][j]
                    vis[i][j]=1
                    ff=0
                    while head<=tail and ff==0:
                        for ii in range(4):
                            xx=que[head][1]+dx[ii]
                            yy=que[head][2]+dy[ii]
                            if xx>=0 and xx<=go_row and yy>=0 and yy<=go_column and arr[xx][yy]==0 and vis[xx][yy]==0:
                                ff=1
                                break
                            elif xx>=0 and xx<=go_row and yy>=0 and yy<=go_column and arr[xx][yy]==3 and vis[xx][yy]==0:
                                ff=1
                                break
                            elif xx>=0 and xx<=go_row and yy>=0 and yy<=go_column and arr[xx][yy]==4 and vis[xx][yy]==0:
                                ff=1
                                break
                            elif xx>=0 and xx<=go_row and yy>=0 and yy<=go_column and arr[xx][yy]==m and vis[xx][yy]==0:
                                tail=tail+1
                                vis[xx][yy]=1
                                que[tail][1]=xx
                                que[tail][2]=yy
                        head=head+1
                    if ff == 0:
                        que = []
                        for ii in range(5000):
                            tmp = []
                            for jj in range(5):
                                tmp.append(0)
                            que.append(tmp)
                        vis = []
                        for ii in range(50):
                            tmp = []
                            for jj in range(50):
                                tmp.append(0)
                            vis.append(tmp)
                        head = tail = 1
                        que[head][1] = i
                        que[head][2] = j
                        m=arr[i][j]
                        arr[i][j]=m+2
                        while head <= tail:
                            for ii in range(4):
                                xx=que[head][1]+dx[ii]
                                yy=que[head][2]+dy[ii]
                                if xx >= 0 and xx <= go_row and yy >= 0 and yy <= go_column and arr[xx][yy]==m and vis[xx][yy]==0:
                                    tail=tail+1
                                    vis[xx][yy]=1
                                    que[tail][1]=xx
                                    que[tail][2]=yy
                                    arr[xx][yy]=arr[xx][yy]+2
                            head = head + 1
        sum1=0
        sum2=0
        for i in range(go_row + 1):
            for j in range(go_column + 1):
                if arr[i][j]==1 or arr[i][j]==4:
                    sum1=sum1+1
                if arr[i][j]==2 or arr[i][j]==3:
                    sum2=sum2+1
        if sum1>((go_row + 1)*(go_column + 1)/2) :
            canvas.delete("all")
            print("执黑子者胜利")
        if sum2>((go_row + 1)*(go_column + 1)/2) :
            canvas.delete("all")
            print("执白子者胜利")
        canvas.delete("all")
        canvas_print()



root.title("围棋（人人对战版）")
root.minsize(window_minsize, window_minsize)
root.configure(bg="yellow")
root.wm_attributes("-transparentcolor", "yellow")
canvas.configure(width=window_minsize, height=window_minsize, bg="#D5B092")
canvas.pack()
root.update()
root.bind("<Configure>", canvas_resize)
canvas.bind("<Motion>", canvas_dot)
canvas.bind("<Button-1>", canvas_go)
canvas_print()
root.mainloop()
