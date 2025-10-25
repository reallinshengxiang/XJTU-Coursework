#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e3+10,M=1e4+10,inf=0x3f3f3f3f3f,maxx=1e9;
ll n,m,s,dis[N],done[N],head[N],cnt,inq[N],neg[N],d[N];
struct node{
	ll id,dis;
	node(ll id,ll dis):id(id),dis(dis){}
	bool operator<(const node&a) const
	{return dis>a.dis;}
};
struct Edge{
	ll to,next,w;
};
Edge edge[M];
void init()
{
	for(ll i=0;i<=N-1;i++) head[i]=-1;
	for(ll i=0;i<=M-1;i++) edge[i].next=-1;
	cnt=0;
}
void addedge(ll u,ll v,ll w)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
ll spfa(ll st)
{
	memset(neg,0,sizeof(neg));
	neg[st]=1;
	for(ll i=0;i<=n;i++)
	{
		dis[i]=inf;
		inq[i]=0;
	}
	dis[st]=0;
	queue<ll> que;
	que.push(st);
	inq[st]=1;
	while(!que.empty())
	{
		ll u=que.front();
		que.pop();
		inq[u]=0;
		for(ll i=head[u];~i;i=edge[i].next)
		{
			ll v=edge[i].to,w=edge[i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				if(!inq[v])
				{
					inq[v]=1;
					que.push(v);
					neg[v]++;
					if(neg[v]>n) return 1;
				}
			}
		}
	}
	return 0;
}
ll dijkstra(ll s)
{
	for(ll i=1;i<=n;i++)
	{
		d[i]=inf;
		done[i]=0;
	}
	d[s]=0;
	priority_queue<node> que;
	que.push(node(s,d[s]));
	while(!que.empty())
	{
		node u=que.top();
		que.pop();
		if(done[u.id]) continue;
		done[u.id]=1;
		for(ll i=head[u.id];~i;i=edge[i].next)
		{
			ll v=edge[i].to,w=edge[i].w;
			if(done[v]) continue;
			if(d[v]>w+d[u.id])
			{
				d[v]=w+d[u.id];
				que.push(node(v,d[v]));
			}
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	for(ll i=1;i<=n;i++) addedge(0,i,0);
	if(spfa(0))
	{
		cout<<"-1";
		return 0;
	}	
	for(ll x=1;x<=n;x++)
	{
		for(ll i=head[x];~i;i=edge[i].next) edge[i].w=edge[i].w+dis[x]-dis[edge[i].to];
	}
	for(ll i=1;i<=n;i++) 
	{
		dijkstra(i);
		ll ans=0;
		for(ll j=1;j<=n;j++) 
		{
			if(d[j]==inf) ans=ans+maxx*j;
			else ans=ans+j*(d[j]+dis[j]-dis[i]);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
 } 
