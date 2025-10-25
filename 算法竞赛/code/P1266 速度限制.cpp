#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double inf=1e10+10;
ll n,m,d,done[155][510];
double dis[155][510];
struct edge{
	ll from,to,v,w;
	edge(ll from,ll to,ll v,ll w):from(from),to(to),v(v),w(w){}
};
vector<edge> e[155];
struct node{
	double time;
	ll id,v;
	node(double time,ll id,ll v):time(time),id(id),v(v){}
	bool operator<(const node&a) const
	{return time>a.time;}
};
struct Node{
	ll id,v;
};
Node pre[155][510];
ll dijkstra()
{
	for(ll i=1;i<=n+1;i++)
	{
		for(ll j=1;j<=501;j++) dis[i][j]=inf;
	}
	dis[1][70]=0;
	priority_queue<node> que;
	que.push(node(0,1,70));
	while(!que.empty())
	{
		node u=que.top();
		que.pop();
		if(done[u.id][u.v]) continue;
		done[u.id][u.v]=1;
		for(ll i=0;i<e[u.id].size();i++)
		{
			edge y=e[u.id][i];			
			if(y.v)
			{
				if(dis[y.to][y.v]>dis[u.id][u.v]+(double)y.w/(double)y.v)
				{
					dis[y.to][y.v]=dis[u.id][u.v]+(double)y.w/(double)y.v;
					pre[y.to][y.v]={u.id,u.v};
					que.push(node(dis[y.to][y.v],y.to,y.v));
				}
			}
			else if(y.v==0)
			{
				y.v=u.v;
				if(dis[y.to][y.v]>dis[u.id][u.v]+(double)y.w/(double)y.v)
				{
					dis[y.to][y.v]=dis[u.id][u.v]+(double)y.w/(double)y.v;
					pre[y.to][y.v]={u.id,u.v};
					que.push(node(dis[y.to][y.v],y.to,y.v));
				}
			}
		}
	}
	return 0;
}
void print(ll id,ll v)
{
	if(id==1) 
	{
		cout<<0<<" ";
		return;
	}
	print(pre[id][v].id,pre[id][v].v);
	cout<<id-1<<" ";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>d;
	d++;
	while(m--)
	{
		ll a,b,v,l;
		cin>>a>>b>>v>>l;
		a++;
		b++;
		e[a].push_back(edge(a,b,v,l));
	}
	dijkstra();	
	ll minn=0;
	dis[d][minn]=inf;
    for(ll i=1;i<=501;i++)
    {
    	if(dis[d][i]==inf) continue;
    	if(dis[d][i]<=dis[d][minn])	minn=i;
	}
	print(d,minn);
	return 0;
 } 
