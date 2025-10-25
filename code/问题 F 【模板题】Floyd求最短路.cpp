#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=220;
ll dp[N][N],n,m,k,x,y,z,inf;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,0x3f,sizeof(dp));
	inf=dp[0][0];
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++) dp[i][i]=0;
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		dp[x][y]=z;
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			if(dp[i][k]!=inf)
			for(ll j=1;j<=n;j++)
			{
				if(dp[k][j]!=inf) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(ll i=1;i<=k;i++)
	{
		cin>>x>>y;
		if(dp[x][y]==inf) cout<<"impossible\n";
		else cout<<dp[x][y]<<"\n";
	}
	return 0; 
}
