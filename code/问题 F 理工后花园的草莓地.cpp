#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dx[10]={0,0,1,1,1,-1,-1,-1};
ll dy[10]={1,-1,0,1,-1,0,1,-1};
ll ans,n,m,a[110][110],que[10010][4];
string s;
void search(ll xx,ll yy)
{
	ll x,y,head=1,tail=1;
	ans++;
	que[head][1]=xx;
	que[head][2]=yy;
	a[xx][yy]=ans+1;
	while(head<=tail)
	{
		for(ll i=0;i<=7;i++)
		{
			x=que[head][1]+dx[i];
			y=que[head][2]+dy[i];
			if(x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]==1)
			{
				tail++;
				a[x][y]=ans+1;
				que[tail][1]=x;
				que[tail][2]=y;
			}
		}
		head++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m)
	{
		if(n==0) break;
		memset(a,0,sizeof(a));
		for(ll i=1;i<=n;i++)
		{
			cin>>s;
			for(ll j=1;j<=m;j++) 
			{
				if(s[j-1]=='$') a[i][j]=1;
			}
		}
		ans=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=m;j++) 
			{
				if(a[i][j]==1)  search(i,j);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
