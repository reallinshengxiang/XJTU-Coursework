#include <iostream>
#include <math.h>
#define MAX 100
#define INF 10000
using namespace std;
int len(int s[],int i,int j)  //求单词的总长度
{
    int t=0;
    for (int k=i;k<=j;k++)
    {
        t+=s[k];
    }
    return t;
}
int main()
{
    int n,M;
    cin>>n>>M;             //n单词数，M行宽
    int *s=new int[n+1];    //每个单词的长度数组
    int *c=new int[n+1];    //c[j]为安排1-j的最小费用
    int *pos=new int[n+1];
    int i,j;
    s[0]=0;
    c[0]=0;
    for (int a=1;a<=n;a++)
    {
        scanf("%d",&s[a]);  输入每个单词的长度
        c[a]=INF;
    }
    int
    extra[MAX][MAX],lc[MAX][MAX];
    int t=0;
    int k=0;
    for (i=1;i<=n;i++)  //外循环已经安排的1到i-1的费用
    {
        for (j=i;j<=n;j++)  //内循环是本行安排i-j
        {
            extra[i][j]=M+i-j-len(s,i,j);
            if (extra[i][j]<0)                       //extra[i][j]为多余的空格数
 
                lc[i][j]=INF;                      // 将i~j打印在一行上的费用
            else if (extra[i][j]>=0&&j==n)
                lc[i][j]=0;
            else lc[i][j]=pow(extra[i][j],3); 
            t=c[i-1]+lc[i][j];                   //打印1到j的总费用
            if (t<c[j])
            {
                c[j]=t;
                pos[k]=j;   //k代表单词的划分位置
            }
        }
        k++;
    }
    cout<<c[n]<<endl;
    for (i=0;i<k&&pos[i]>0;i++)
    {
        if (pos[i+1]!=pos[i])  //这点似乎有问题
        {
            cout<<pos[i]<<" ";
        }
    }
    delete []s;
    delete []c;
    return 0;
}
