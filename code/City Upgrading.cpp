#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll dp[N][2],fa[N],x[N],n,T;
vector<ll> g[N];
void add_edge(ll from,ll to)
{
	g[from].push_back(to);
	fa[to]=from;
}
void dfs(ll root)
{
	dp[root][0]=0;
	dp[root][1]=x[root];
	for(ll i=0; i<g[root].size(); i++)
	{
		ll to=g[root][i];
		dfs(to);
		dp[root][1]=dp[root][1]+min(dp[to][0],dp[to][1]);
		dp[root][0]=dp[root][0]+dp[to][1];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		memset(fa,0,sizeof(fa));
		for(ll i=0;i<=N-1;i++) g[i].clear();
		cin>>n;
		for(ll i=1; i<=n; i++) cin>>x[i];
		for(ll i=1; i<=n-1; i++)
		{
			ll k,l;
			cin>>k>>l;
			add_edge(k,l);
		}
		ll t=1;
		while(fa[t]) t=fa[t];
		dfs(t);
		cout<<min(dp[t][0],dp[t][1])<<"\n";
    }
	return 0;
}
