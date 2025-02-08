#include<bits/stdc++.h>
using namespace std;
long long a[110][110];
int main()
{
    long long n,step,x,y,i,j;
    cin>>n;
    step=1;
    a[1][n]=step;
    x=1;
    y=n;
    while(step<n*n)
    {   
       while(x<=n-1&&!a[x+1][y])  a[++x][y]=++step;
       while(y>=2&&!a[x][y-1])  a[x][--y]=++step;
       while(x>=2&&!a[x-1][y]) a[--x][y]=++step;
       while(y<=n-1&&!a[x][y+1]) a[x][++y]=++step;
    }
    for(i=1;i<=n;i++)
    {
	for(j=1;j<=n;j++)
	{
	   cout<<a[i][j]<<" ";
	}
	cout<<endl;
    }
}
