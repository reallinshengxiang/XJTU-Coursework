#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e4+10;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
ll tag[N],length[N],xx[N];
struct scanline{       //定义扫描线
    double y;                       //边的y坐标
    double right_x,left_x;          //边的x坐标:右、左
    int inout;                      //入边为1，出边为-1
    scanline(){}
scanline(double y,double x2,double x1,int io):
y(y),right_x(x2),left_x(x1),inout(io){}
}line[N];
bool cmp(scanline a,scanline b){return a.y<b.y;}
void push_up(int p,int pl,int pr){          //从下往上传递区间值
if(tag[p])    length[p] = xx[pr]-xx[pl];            
       //结点的Tag为正，这个线段对计算宽度有效。计算宽度   
    else if(pl+1 == pr)  length[p] = 0;    //叶子结点没有宽度
    else length[p] = length[ls(p)] + length[rs(p)];
}
void update(int L,int R,int io,int p,int pl,int pr){
    if(L<=pl && pr<=R){                //完全覆盖
        tag[p] += io;                  //结点的标志，用来判断能否用来计算宽度
        push_up(p,pl,pr);
        return;
    }
    if(pl+1 == pr)  return;            //叶子结点
    int mid = (pl+pr) >> 1;
    if(L<=mid)  update(L,R,io,ls(p),pl,mid);
    if(R>mid)   update(L,R,io,rs(p),mid,pr);   //注意不是mid+1
    push_up(p,pl,pr);
}
int main(){    
    int n, t = 0;
    freopen("P1884_7.in","r",stdin);
    while(scanf("%d",&n),n){
        int cnt = 0;        //边的数量，包括入边和出边
        while(n--){ 
            double x1,x2,y1,y2; scanf("%lf%lf%lf%lf",&x1,&y2,&x2,&y1);//输入一个矩形
            line[++cnt] = scanline(y1,x2,x1,1);      //给入边赋值
            xx[cnt] = x1;                            //记录x坐标
            line[++cnt] = scanline(y2,x2,x1,-1);     //给出边赋值
            xx[cnt] = x2;                            //记录x坐标
        }
        sort(xx+1,xx+cnt+1);                         //对所有边的x坐标排序
        sort(line+1,line+cnt+1,cmp);            //对扫描线按y轴方向从低到高排序
        int num = unique(xx+1,xx+cnt+1)-(xx+1); //离散化：用unique去重，返回个数
        //memset(Tag,0,sizeof(Tag));
        //memset(length,0,sizeof(length));              
        double ans = 0;
        for(int i=1;i<=cnt;++i) {                    //扫描所有入边和出边
            int L,R; 
            ans += length[1]*(line[i].y-line[i-1].y);//累加当前扫描线的面积=宽*高
            L = lower_bound(xx+1,xx+num+1,line[i].left_x)-xx; 
                                           //x坐标离散化：用相对位置代替坐标值
            R = lower_bound(xx+1,xx+num+1,line[i].right_x)-xx;   
            update(L,R,line[i].inout,1,1,num);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",++t,ans);
    }
    return 0;
}
