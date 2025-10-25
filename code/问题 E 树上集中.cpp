#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct Edge{
	ll to,next;
};
Edge edge[2*N];
ll head[2*N],cnt,fa[N][20],deep[N];
void init()
{
    for(ll i=0;i<=2*N-1;i++) edge[i].next=head[i]=-1;
}
void addedge(ll u,ll v)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(ll x,ll father)
{
	deep[x]=deep[father]+1;
	fa[x][0]=father;
	for(ll i=1;(1<<i)<=deep[x];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(ll i=head[x];~i;i=edge[i].next)
	{
		if(edge[i].to!=father) dfs(edge[i].to,x);
	}
}
ll lca(ll x,ll y)
{
	if(deep[x]<deep[y]) swap(x,y);
	for(ll i=19;i>=0;i--)
	{
		if(deep[x]-(1<<i)>=deep[y]) x=fa[x][i];
	}
	if(x==y) return x;
	for(ll i=19;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	} 
	return fa[x][0];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	init();
	cin>>n;
	for(ll i=1;i<=n-1;i++)
	{
		ll u,v;
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,0);
	cin>>m;
	while(m--)
	{
		ll a,b,c;
		cin>>a>>b;
		c=lca(a,b);
		if(deep[a]==deep[b]) cout<<deep[c]<<"\n";		
		cout<<lca(a,b)<<"\n";
	}
	return 0;
}
