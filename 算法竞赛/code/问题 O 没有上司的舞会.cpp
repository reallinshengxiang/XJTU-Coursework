#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> g[6010];
ll h[6010],dp[6010][2],fa[6010],n;
void addedge(ll dad,ll son)
{
	g[dad].push_back(son);
	fa[son]=dad;
}
void dfs(ll t)
{
	dp[t][0]=0;
	dp[t][1]=h[t];
	for(ll i=0;i<g[t].size();i++)
	{
		ll son=g[t][i];
		dfs(son);
		dp[t][1]=dp[t][1]+dp[son][0];
		dp[t][0]=dp[t][0]+max(dp[son][1],dp[son][0]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)  cin>>h[i];
	for(ll i=1;i<=n-1;i++)
	{
		ll l,k;
		cin>>l>>k;
		addedge(k,l);
	}
	ll t=1;
	while(fa[t]) t=fa[t];
	dfs(t);
	cout<<max(dp[t][0],dp[t][1]);
	return 0;
}
