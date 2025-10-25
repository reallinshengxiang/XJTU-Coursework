#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10,M=5e5+10,inf=0x3f3f3f3f3f;
ll n,m,dis[2][N],col[2][N],done[N],T,k,p[N],u[M],v[M],w[M];
struct edge{
	ll from,to,w;
	edge(ll from,ll to,ll w):from(from),to(to),w(w){}
};
vector<edge> e[N],e1[N];
struct node{
	ll id,dis;
	node(ll id,ll dis):id(id),dis(dis){}
	bool operator<(const node&a) const
	{return dis>a.dis;}
};
ll dijkstra(ll *dis,ll *col)
{
	for(ll i=1;i<=n;i++)
	{
		dis[i]=inf;
		done[i]=0;
	}
	priority_queue<node> que;
	for(ll i=1;i<=k;i++) 
	{
		dis[p[i]]=0;
		col[p[i]]=p[i];
		que.push(node(p[i],0));
	}
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
			if(dis[y.to]>y.w+u.dis)
			{
				dis[y.to]=y.w+u.dis;
				col[y.to]=col[u.id];
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
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
	    for(ll i=1;i<=m;i++)
	    {
		   cin>>u[i]>>v[i]>>w[i];
		   e[u[i]].push_back(edge(u[i],v[i],w[i]));
	    }
	    for(ll i=1;i<=k;i++) cin>>p[i];
	    dijkstra(dis[0],col[0]);
	    for(ll i=0;i<=n;i++) e[i].clear(); 
	    for(ll i=1;i<=m;i++)   e[v[i]].push_back(edge(v[i],u[i],w[i]));
	    dijkstra(dis[1],col[1]);
	    ll ans=inf;
	    for(ll i=1;i<=m;i++)
	    {
	    	
	    	if(col[0][u[i]]&&col[1][v[i]]&&col[0][u[i]]!=col[1][v[i]]) 	ans=min(ans,dis[0][u[i]]+dis[1][v[i]]+w[i]);
		}
		cout<<ans<<"\n";
		for(ll i=0;i<=n;i++) e[i].clear(); 
	}
	
	return 0;
 } 
