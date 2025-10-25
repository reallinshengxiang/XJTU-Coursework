#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct Edge{
	ll to,next;
};
Edge edge[N<<1];
ll head[N],cnt,deep[N],fa[N][22];
void addedge(ll x,ll y)
{
	cnt++;
	edge[cnt].to=y;
	edge[cnt].next=head[x];	
	head[x]=cnt;
}
void dfs(ll x,ll father)
{	
	fa[x][0]=father;
	deep[x]=deep[father]+1;
	for(ll i=1;(1<<i)<=deep[x];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(ll i=head[x];i;i=edge[i].next)
	{
		if(edge[i].to!=father) dfs(edge[i].to,x);
	}
}
ll lca(ll x,ll y)
{
	if(deep[x]<deep[y]) swap(x,y);
	for(ll i=20;i>=0;i--)
	{
		if(deep[x]-(1<<i)>=deep[y])  x=fa[x][i];
	}
	if(x==y) return x;
	for(ll i=20;i>=0;i--)
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
	ll x,y,n,q;
	cin>>n;	
	for(ll i=1;i<=n-1;i++)
	{
		cin>>x>>y;
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,0);
	cin>>q;
	for(ll i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<deep[x]+deep[y]-2*deep[lca(x, y)]<<"\n";
	}
	return 0;
}
