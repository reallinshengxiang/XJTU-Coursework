#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
struct Edge{
	ll to,next;
};
Edge edge[N];
ll head[N],cnt,n1,n2,m,ans,match[N],vis[N];
void add_edge(ll from,ll to)
{
	cnt++;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool dfs(ll x)
{
	for(ll i=head[x];~i;i=edge[i].next)
	{
		ll to=edge[i].to;
		if(vis[to]) continue;
		vis[to]=1;
		if(!match[to]||dfs(match[to]))
		{
			match[to]=x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n1>>n2>>m;
	for(ll i=1;i<=n1+n2;i++) head[i]=-1;
	for(ll i=1;i<=m;i++) edge[i].next=-1;
	for(ll i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		add_edge(x,y);
	}
	for(ll i=1;i<=n1;i++)
	{
		if(dfs(i)) ans++;
	}
	cout<<ans;
	return 0;
}
