#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=0x3f3f3f3f;
const ll N=5e3+10,M=1e5+10;
struct edge{
	ll to,w;
}; 
vector<edge> e[M],e2[M];
struct node{
	ll id,dis;
	node(ll id,ll dis):id(id),dis(dis){}
	bool operator<(const node&u) const {return dis>u.dis;}
};
ll dist[N],done[N];
void dijkstra(ll s)
{
	for(ll i=0;i<=N-1;i++) dist[i]=inf,done[i]=0;
	dist[s]=0;
	priority_queue<node> q;
	q.push(node(s,dist[s]));
	while(!q.empty())
	{
		node u=q.top();
		q.pop();
		if(done[u.id]) continue;
		done[u.id]=1;
		for(ll i=0;i<e2[u.id].size();i++)
		{
			edge y=e2[u.id][i];
			if(done[y.to]) continue;
			if(dist[y.to]>u.dis+y.w)
			{
				dist[y.to]=u.dis+y.w;
				q.push(node(y.to,dist[y.to]));
			}
		}
	} 
}
struct point{
	ll v,g,h;
	point(ll v,ll g,ll h):v(v),g(g),h(h){}
	bool operator<(const point&b) const {return g+h>b.g+b.h;}
};
ll times[N];
ll astar(ll s,ll t,ll k)
{
	memset(times,0,sizeof(times));
	priority_queue<point> q;
	q.push(point(s,0,0));
	while(!q.empty())
	{
		point p=q.top();
		q.pop();
		times[p.v]++;
		if(times[p.v]==k&&p.v==t) return p.g+p.h;
		for(ll i=0;i<e[p.v].size();i++)
		{
			edge y=e[p.v][i];
			q.push(point(y.to,p.g+y.w,dist[y.to]));
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	while(m--)
	{
		ll a,b,w;
		cin>>a>>b>>w;
		e[a].push_back((edge){b,w});
		e[b].push_back((edge){a,w});
		e2[a].push_back((edge){b,w});
		e2[b].push_back((edge){a,w});
	}
	dijkstra(n);
	cout<<astar(1,n,2);
	return 0;
}
