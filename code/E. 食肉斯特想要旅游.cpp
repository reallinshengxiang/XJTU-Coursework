#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=5e4+10;
const ll inf=0x3f3f3f3f3f3f;
struct Edge{
	ll x,y,z;
};
Edge edge[M];
struct EDGE{
	ll to,next,z;
};
EDGE eg[M];
bool cmp(Edge a,Edge b){return a.z>b.z;}
ll f[M],n,m,w[M][22],fa[M][22],cnt,head[M],vis[M],deep[M];
void addedge(ll x,ll y,ll z)
{
	cnt++;
	eg[cnt].to=y;
	eg[cnt].next=head[x];
	eg[cnt].z=z;
	head[x]=cnt;
}
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void kruskal()
{
	sort(edge+1,edge+m+1,cmp);
	for(ll i=1;i<=n;i++) f[i]=i;
	for(ll i=1;i<=m;i++)
	{
		if(find_set(edge[i].x)!=find_set(edge[i].y))
		{
			f[find_set(edge[i].x)]=find_set(edge[i].y);
			addedge(edge[i].x,edge[i].y,edge[i].z);
			addedge(edge[i].y,edge[i].x,edge[i].z);
		}
	}
}
void dfs(ll x)
{
	vis[x]=1;
	for(ll i=head[x];i;i=eg[i].next)
	{
		ll y=eg[i].to;
		if(vis[y]) continue;
		deep[y]=deep[x]+1;
		w[y][0]=eg[i].z;
		fa[y][0]=x;
		for(int j=1; j<=20; j++)
		{
			fa[y][j]=fa[fa[y][j-1]][j-1];
			w[y][j]=min(w[y][j-1],w[fa[y][j-1]][j-1]);
		}
		dfs(y);
	}
}
ll lca(ll x,ll y)
{
	if(find_set(x)!=find_set(y)) return -1;
	ll ans=inf;
	if(deep[x]<deep[y]) swap(x,y);
	for(ll i=20;i>=0;i--)
	{
		if(deep[fa[x][i]]>=deep[y])
		{
			ans=min(ans,w[x][i]);
			x=fa[x][i];
		}
	}
	if(x==y) return ans;
	for(ll i=20;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			ans=min(ans,min(w[x][i],w[y][i]));
			x=fa[x][i];
			y=fa[y][i];		
		}
	}
	ans=min(ans,min(w[x][0],w[y][0]));
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(w,0x3f,sizeof(w));
	for(ll i=1;i<=m;i++) cin>>edge[i].x>>edge[i].y>>edge[i].z;
	kruskal();
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			fa[i][1]=0;
			dfs(i);
		}
	}
	ll q;
	cin>>q;
	for(ll i=1;i<=q;i++)
	{
		ll x,y;
		cin>>x>>y;
		cout<<lca(x,y)<<"\n";
	}
	return 0;
}
