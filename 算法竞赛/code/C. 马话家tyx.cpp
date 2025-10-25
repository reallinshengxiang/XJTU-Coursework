#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dx[9]= {1,2,2,1,-1,-2,-2,-1};
ll dy[9]= {-2,-1,1,2,2,1,-1,-2};
ll n,m,a[2001][2001],s[2001][2001],ans;
ll dfs(ll x,ll y)
{
	if(s[x][y]) return s[x][y];
	s[x][y]=a[x][y];
	for(ll i=0;i<=7;i++)
	{
		ll xx=dx[i]+x;
		ll yy=dy[i]+y;
		if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&a[x][y]>a[xx][yy])
		{
			dfs(xx,yy);
			s[x][y]=max(s[x][y],s[xx][yy]+a[x][y]);
		}
	}
	return s[x][y];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>a[i][j];
    }
	for(ll i=1; i<=n; i++)
	{
		for(ll j=1;j<=m;j++)  ans=max(ans,dfs(i,j));
	}
	cout<<ans;
	return 0;
}
