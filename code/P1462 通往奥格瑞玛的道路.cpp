#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10,inf=0x3f3f3f3f3f3f3f;
ll n,m,s,dis[N],done[N],f[N],b;
struct edge{
	ll from,to,w;
	edge(ll from,ll to,ll w):from(from),to(to),w(w){}
};
vector<edge> e[N];
struct node{
	ll id,dis;
	node(ll id,ll dis):id(id),dis(dis){}
	bool operator<(const node&a) const
	{return dis>a.dis;}
};
ll dijkstra(ll x)
{
	for(ll i=1;i<=n;i++)
	{
		dis[i]=inf;
		done[i]=0;
	}
	dis[1]=0;
	priority_queue<node> que;
	que.push(node(1,dis[1]));
	while(!que.empty())
	{
		node u=que.top();
		que.pop();
		if(done[u.id]) continue;
		done[u.id]=1;
		for(ll i=0;i<e[u.id].size();i++)
		{
			edge y=e[u.id][i];
			if(done[y.to]) continue;
			if(f[y.to]>x) continue;
			if(dis[y.to]>y.w+u.dis)
			{
				dis[y.to]=y.w+u.dis;
				que.push(node(y.to,dis[y.to]));
			}
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll l,r=0;
	cin>>n>>m>>b;
	for(ll i=1;i<=n;i++) 
	{
		cin>>f[i];
		r=max(r,f[i]);
	}
	l=max(f[1],f[n]);
	while(m--)
	{
		ll u,w,v;
		cin>>u>>v>>w;
		if(u==v) continue;
		e[u].push_back(edge(u,v,w));
		e[v].push_back(edge(v,u,w));
	}
	ll ans;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		dijkstra(mid);
		if(dis[n]>b) l=mid+1;
		else r=mid-1;
	}
	dijkstra(l);
	if(dis[n]>b) cout<<"AFK";
	else cout<<ans;
	return 0;
 }  
