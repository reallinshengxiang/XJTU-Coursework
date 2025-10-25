#include<bits/stdc++.h>
using namespace std;
int ls(int p){ return p<<1;  }   
int rs(int p){ return p<<1|1;}    
const int N = 20005;
int Tag[N];           
double length[N];      
double xx[N];         
struct ScanLine{      
    double y;                     
    double right_x,left_x;          
    int inout;                    
    ScanLine(){}
ScanLine(double y,double x2,double x1,int io):
y(y),right_x(x2),left_x(x1),inout(io){}
}line[N];
bool cmp(ScanLine &a,ScanLine &b) { return a.y<b.y; } 
void pushup(int p,int pl,int pr){          
if(Tag[p])    length[p] = xx[pr]-xx[pl];            
    else if(pl+1 == pr)  length[p] = 0;   
    else length[p] = length[ls(p)] + length[rs(p)];
}
void update(int L,int R,int io,int p,int pl,int pr){
    if(L<=pl && pr<=R){               
        Tag[p] += io;                  
        pushup(p,pl,pr);
        return;
    }
    if(pl+1 == pr)  return;           
    int mid = (pl+pr) >> 1;
    if(L<=mid)  update(L,R,io,ls(p),pl,mid);
    if(R>mid)   update(L,R,io,rs(p),mid,pr);   
    pushup(p,pl,pr);
}
int main(){    
    int n, t = 0;
    while(scanf("%d",&n),n){
        int cnt = 0;      
        while(n--){ 
            double x1,x2,y1,y2; scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            line[++cnt] = ScanLine(y1,x2,x1,1);      
            xx[cnt] = x1;                           
            line[++cnt] = ScanLine(y2,x2,x1,-1);     
            xx[cnt] = x2;                           
        }
        sort(xx+1,xx+cnt+1);                        
        sort(line+1,line+cnt+1,cmp);          
        int num = unique(xx+1,xx+cnt+1)-(xx+1);
        memset(Tag,0,sizeof(Tag));
        memset(length,0,sizeof(length));              
        double ans = 0;
        for(int i=1;i<=cnt;++i) {                  
            int L,R; 
            ans += length[1]*(line[i].y-line[i-1].y);
            L = lower_bound(xx+1,xx+num+1,line[i].left_x)-xx; 
            R = lower_bound(xx+1,xx+num+1,line[i].right_x)-xx;   
            update(L,R,line[i].inout,1,1,num);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",++t,ans);
    }
    return 0;
}
