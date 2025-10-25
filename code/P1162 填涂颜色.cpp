#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	ll x,y;
};
ll dx[5]={0,0,1,-1};
ll dy[5]={1,-1,0,0};
const ll N=33;
ll a[N][N],b[N][N],vis[N][N],n,que[1010][2];
bool check(ll x,ll y)
{
	if(x==1||x==n||y==1||y==n) return 1;
	return 0;
}
void search(ll x,ll y)
{
	ll flag=0,head=1,tail=1;
	if(check(x,y)) flag=1;
	que[head][0]=x;
	que[tail][1]=y;
	vis[x][y]=1;
	while(head<=tail)
	{
		for(ll i=0;i<=3;i++)
		{
			ll xx=que[head][0]+dx[i];
			ll yy=que[head][1]+dy[i];
			if(!vis[xx][yy]&&xx>=1&&yy>=1&&xx<=n&&yy<=n&&a[xx][yy]==0)
			{
				if(check(xx,yy)) flag=1;
				tail++;
				vis[xx][yy]=1;
				que[tail][0]=xx;
				que[tail][1]=yy;
			}
		}
		head++;
	}
	if(flag)
	{
		for(ll i=1;i<=tail;i++) b[que[i][0]][que[i][1]]=3;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) 
		{
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) 
		{
			if(b[i][j]==0) search(i,j);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(a[i][j]==1) cout<<"1 ";
			else if(b[i][j]==3) cout<<"0 ";
			else cout<<"2 ";
		}
		cout<<"\n";
	}
	return 0;
}
