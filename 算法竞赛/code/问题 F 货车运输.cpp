#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10,M=1e5+10,inf=0x7fffffff;
struct Edge{
	ll x,y,z,next;
}; 
Edge edge[M],e[M];
bool cmp(Edge a,Edge b){ return a.z>b.z;}
ll f[N],cnt,head[N],n,m,q,fa[M][23],deep[M],minn[M][23];
void addedge(ll x,ll y,ll z)
{
	cnt++;
	e[cnt].y=y;
	e[cnt].z=z;
	e[cnt].next=head[x];
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
	ll cnt1=0;
	for(ll i=1;i<=m;i++)
	{
		if(cnt1==n-1) break;
		ll e1=find_set(edge[i].x);
		ll e2=find_set(edge[i].y);
		if(e1==e2) continue;
		f[e1]=e2;
		cnt1++;
		addedge(edge[i].x,edge[i].y,edge[i].z);
		addedge(edge[i].y,edge[i].x,edge[i].z);
	}
}
void dfs(ll x,ll father)
{	
	deep[x]=deep[father]+1;
	fa[x][0]=father;
	for(ll i=1;(1<<i)<=deep[x];i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
		minn[x][i]=min(minn[fa[x][i-1]][i-1],minn[x][i-1]);
	}
	
	for(ll i=head[x];~i;i=e[i].next)
	{
		if(e[i].y!=father) 
		{
			minn[e[i].y][0]=e[i].z;
			dfs(e[i].y,x);
		}
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
ll search(ll x,ll y)
{
	ll ans=inf;
	for(ll i=19;i>=0;i--)
	{
		if(deep[x]-(1<<i)>=deep[y]) 
		{
			ans=min(ans,minn[x][i]);
			x=fa[x][i];
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++) cin>>edge[i].x>>edge[i].y>>edge[i].z;
	for(ll i=1;i<=n;i++) head[i]=-1;
	kruskal();	
	for(ll i=1;i<=n;i++)
	{
		if(f[i]==i)
		{
			minn[i][0]=inf;
			dfs(i,0);
		}
	}
	cin>>q;
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		if(find_set(x)!=find_set(y)) cout<<"-1\n";
		else
		{
			ll aa=lca(x,y);
			cout<<min(search(x,aa),search(y,aa))<<"\n";
		}
	} 
	return 0;
}
