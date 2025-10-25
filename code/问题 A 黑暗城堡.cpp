#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=(1<<31)-1;
const ll inf=0x3f3f3f3f3f;
const ll M=1e6+10,N=1010;
struct edge{
	ll to,w;
	edge(ll to=0,ll w=0):to(to),w(w){}
};
vector<edge> e[M];
struct node{
	ll id,ndis;
	node(ll id=0,ll ndis=0):id(id),ndis(ndis){}
	bool operator<(const node &a) const
	{return ndis>a.ndis;}
};
ll n,m,dis[N],done[N],p[N];
void dijkstra(ll x)
{
	ll s=1;
	for(ll i=1;i<=n;i++)
	{
		if(x==0) dis[i]=inf;
		done[i]=0;
	}
	dis[s]=0;
	p[s]=1;
	priority_queue<node> q;
	q.push(node(s,dis[s]));
	while(!q.empty())
	{
		node u=q.top();
		q.pop();
		if(done[u.id]) continue;
		done[u.id]=1;
		for(ll i=0;i<e[u.id].size();i++)
		{
			edge y=e[u.id][i];
			if(done[y.to]) continue;
			if(dis[y.to]>=y.w+u.ndis)
			{
				if(x==1) p[y.to]++;
				dis[y.to]=y.w+u.ndis;
				q.push(node(y.to,dis[y.to]));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		e[u].push_back(edge(v,w));
		e[v].push_back(edge(u,w));
	}
	dijkstra(0);
	dijkstra(1);
	ll ans=1;
	for(ll i=1;i<=n;i++) ans=ans*p[i]%mod;
	cout<<ans;
	return 0;
}
