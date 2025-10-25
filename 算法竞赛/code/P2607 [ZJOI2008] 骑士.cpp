#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+100;
vector<ll> edge[N];
ll fa[N],val[N],mark,vis[N],dp[N][2];
void addedge(ll from,ll to)
{
	edge[from].push_back(to);
	fa[to]=from;
}
void dfs(ll u)
{
	dp[u][0]=0;
	dp[u][1]=val[u];
	vis[u]=1;
	for(ll i=0;i<edge[u].size();i++)
	{
		ll v=edge[u][i];
		if(v==mark) continue;
		dfs(v);
		dp[u][1]=dp[u][1]+dp[v][0];
		dp[u][0]=dp[u][0]+max(dp[v][1],dp[v][0]);
	}
}
ll check(ll u)
{
	vis[u]=1;
	ll f=fa[u];
	if(vis[f]) return f;
	else check(f);
}
ll solve(ll u)
{
	ll res=0;
	mark=check(u);
	dfs(mark);
	res=max(res,dp[mark][0]);
	mark=fa[mark];
	dfs(mark);
	res=max(res,dp[mark][0]);
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll d;
		cin>>val[i]>>d;
		addedge(d,i);
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i]) ans=ans+solve(i);
		
	}
	cout<<ans;
	return 0;
}

