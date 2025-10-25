#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1024*1024+10;
ll dp[N],x,n,m,k,t,v[N],inf;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	memset(dp,127/3,sizeof(dp));
	inf=dp[0];
	for(ll i=1;i<=n;i++)
	{
		x=0;
		for(ll j=1;j<=k;j++)
		{
			cin>>t;
			t--;
			x=x|(1<<t);
			dp[x]=1;
		}
		v[i]=x;
	}
	for(ll i=0;i<(1<<m);i++)
	{
		for(ll j=1;j<=n;j++)
		{
			dp[i|v[j]]=min(dp[i|v[j]],dp[i]+1);
		}
	}
	if(dp[(1<<m)-1]==inf) cout<<"-1";
	else cout<<dp[(1<<m)-1];
	return 0;
}
