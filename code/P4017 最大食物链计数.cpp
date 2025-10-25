#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=80112002;
ll ans,a,b,m,n,x,dp[5050],flag[5050];
vector<ll> g[5050];
ll dfs(ll x)
{
	if(!g[x].size()) 
	{
		dp[x]=1;
		return dp[x];
	}
	if(dp[x]) return dp[x];
	ll ans=0;
	for(ll i=0;i<g[x].size();i++)
	{
		ll y=g[x][i];
		dfs(y);
		ans=(ans+dp[y])%mod;
		ans=ans%mod;
	}
	dp[x]=ans;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>a>>b;
		g[b].push_back(a);
		flag[a]=1;
	}
	for(ll i=1;i<=n;i++)
	{
		if(!flag[i]) 	ans=(ans+dfs(i))%mod;
	}
	cout<<ans;
	return 0;
}
