#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e4+10;
ll ans,low[N],num[N],iscut[N],dfn,n,m,st;
vector<ll> edge[N];
void dfs(ll u,ll fa)
{
	dfn++;
	low[u]=num[u]=dfn;
	ll child=0;
	for(ll i=0;i<edge[u].size();i++)
	{
		ll v=edge[u][i];
		if(!num[v])
		{
			child++;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=num[u]&&u!=st)  iscut[u]=1;
		}
		else if(num[v]<num[u]&&v!=fa) low[u]=min(low[u],num[v]);
	}
	if(u==st&&child>=2) iscut[u]=1;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(ll i=1;i<=n;i++)
	{
		if(num[i]==0) st=i,dfs(i,-1);
	}
	for(ll i=1;i<=n;i++) ans=ans+iscut[i];
	cout<<ans<<"\n";
	for(ll i=1;i<=n;i++)
	{
		if(iscut[i]) cout<<i<<" ";
	}
	return 0;
} 
