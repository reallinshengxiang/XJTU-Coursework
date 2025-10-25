#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=0x3f3f3f3f3f3f;
const ll N=1e6+10;
struct edge
{
	ll to,w;
};
struct node
{
	ll id,dis;
	bool operator<(const node& n) const
	{
		return dis>n.dis;
	}
};
vector<edge> e[N];
ll n,m,dist[N],done[N],u[N],v[N],w[N];
void dijkstra()
{
	for(ll i=1;i<=n;i++) dist[i]=inf;
	for(ll i=1;i<=n;i++) done[i]=0;
	dist[1]=0;
	priority_queue<node> q;
	q.push({1,0});
	while(!q.empty())
	{
		node u=q.top();
		cout<<u.dis<<"\n";
		q.pop();
		if(done[u.id])  continue;
		done[u.id]=1;
		for(ll i=0; i<e[u.id].size(); i++)
		{
			edge v=e[u.id][i];
			if(done[v.to]) continue;
			if(dist[v.to]>dist[u.id]+v.w)
			{
				dist[v.to]=dist[u.id]+v.w;
				q.push({v.to,dist[v.to]});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=m; i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		e[u[i]].push_back({v[i],w[i]});
	}
	dijkstra();
	ll sum=0;
	for(ll i=1;i<=n;i++) 
	{
		if(dist[i]==inf)
		{
			cout<<"-1";
			return 0;
		}
		sum=sum+dist[i];
	}
	for(ll i=1; i<=m; i++)	e[i].clear();
	for(ll i=1;i<=m;i++) e[v[i]].push_back({u[i],w[i]});
	dijkstra();
	for(ll i=1;i<=n;i++) 
	{
		if(dist[i]==inf)
		{
			cout<<"-1";
			return 0;
		}
		sum=sum+dist[i];
	}
	cout<<sum;
	return 0;
}
