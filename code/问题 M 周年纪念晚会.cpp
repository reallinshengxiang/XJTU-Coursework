#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> g[6010];
ll p[6010],dp[6010][2],n,l,k,fa[6010];
void add_edge(ll son,ll father)
{
	g[father].push_back(son);
	fa[son]=father;
}
void dfs(ll x)
{
	dp[x][0]=0;
	dp[x][1]=p[x];
	for(ll i=0;i<g[x].size();i++)
	{
		ll y=g[x][i];
		dfs(y);
		dp[x][1]=dp[x][1]+dp[y][0];
		dp[x][0]=dp[x][0]+max(dp[y][1],dp[y][0]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)  cin>>p[i];
	while(cin>>l>>k)
	{
		if(l==0&&k==0) break;
		add_edge(l,k);
	}
	ll t=1;
	while(fa[t]) t=fa[t];
	dfs(t);
	cout<<max(dp[t][0],dp[t][1]);
	return 0;
} 
