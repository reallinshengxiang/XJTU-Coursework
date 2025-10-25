#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=4e5+10;
struct edge{
	ll to,w;
	edge(ll to=0,ll w=0):to(to),w(w){}
};
vector<edge> e[N];
ll sum[N],ans,n;
void dfs(ll x,ll father)
{
	sum[x]=1;
	for(ll i=0;i<e[x].size();i++)
	{
		ll y=e[x][i].to;
		if(y==father) continue;
		dfs(y,x);
		sum[x]=sum[y]+sum[x];
		ans=ans+e[x][i].w*sum[y]*(n-sum[y]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n-1;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		e[u].push_back(edge(v,w));
		e[v].push_back(edge(u,w));
	}
	dfs(1,0);
	ans=ans*4;
	cout<<ans;
	return 0;
}
