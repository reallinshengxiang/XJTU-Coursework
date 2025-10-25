#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Edge{
	ll x,y,w,flag;
};
Edge edge[10010];
struct bian{
	ll to,nex,w;
};
bian e[10010];
ll head[550],cnt,f[550],n,m,maxx[550][550],sum,s,tt;
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
void addedge(ll from,ll to,ll w)
{
	cnt++;
	e[cnt].to=to;
	e[cnt].nex=head[from];
	e[cnt].w=w;
	head[from]=cnt; 
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
	sum=0;
	ll mm=0;
	for(ll i=1;i<=m;i++)
	{
		ll e1=find_set(edge[i].x);
		ll e2=find_set(edge[i].y);
		if(e1!=e2)
		{
			sum=sum+edge[i].w;
			f[e1]=e2;
			addedge(edge[i].x,edge[i].y,edge[i].w);
			addedge(edge[i].y,edge[i].x,edge[i].w);
			edge[i].flag=1;
			mm++;
			if(mm==n-1) break;
		}
	}
}
void dfs(ll x)
{
	for(ll i=head[x];i;i=e[i].nex)
	{
		if(e[i].to==s) continue;
		if(!maxx[s][e[i].to])
		{
			maxx[s][e[i].to]=max(maxx[s][x],e[i].w);
			dfs(e[i].to);
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++) cin>>edge[i].x>>edge[i].y>>edge[i].w;
	kruskal();
	for(ll i=1;i<=n;i++) 
	{
		s=i;
		dfs(i);
	}
	ll ans=1e15;
	for(ll i=1;i<=m;i++)
	{
		if(!edge[i].flag)
		{			
			if(edge[i].w>maxx[edge[i].x][edge[i].y]) ans=min(ans,sum-maxx[edge[i].x][edge[i].y]+edge[i].w);
		}
	}
	cout<<ans;
	return 0;
}
