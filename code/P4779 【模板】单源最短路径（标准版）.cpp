#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e3+10,inf=0x3f3f3f3f3f;
ll n,m,s,dis[N],done[N];
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
ll dijkstra()
{
	for(ll i=1;i<=n;i++)
	{
		dis[i]=inf;
		done[i]=0;
	}
	dis[s]=0;
	priority_queue<node> que;
	que.push(node(s,dis[s]));
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
	cin>>n>>m>>s;
	while(m--)
	{
		ll u,w,v;
		cin>>u>>v>>w;
		e[u].push_back(edge(u,v,w));
	}
	dijkstra();
	for(ll i=1;i<=n;i++) 
	{
		if(dis[i]==inf) cout<<"2147483647 ";
		else cout<<dis[i]<<" ";
	}
	return 0;
 } 
