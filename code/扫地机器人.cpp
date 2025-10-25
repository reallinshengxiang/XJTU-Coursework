#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll t[N],n,u,v,ans,vis[N];
vector<ll> e[N];
ll dfs(ll now,ll sum)
{
	sum=t[now];
	ll ss=0;
	vis[now]=1;
	for(ll i=0;i<e[now].size();i++)
	{
		ll y=e[now][i];
		if(vis[y]) continue;
		vis[y]=1;
		ss=max(ss,dfs(y,sum));
	}
	return sum+ss;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>t[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll ii=1;ii<=n;ii++) vis[ii]=0;
		ans=max(ans,dfs(i,0));
	}
	cout<<ans;
	return 0;
}
