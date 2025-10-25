#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=6e5+10,N=3e5+10,inf=0x3f3f3f3f3f3f;
struct edge{
	ll to,w;
};
vector<edge> e[M];
struct node{
	ll id,ndis;
	bool operator<(const node &x) const
	{
		return ndis>x.ndis; 
	}
};
ll n,m,dis[N],vis[N],d1,d2;
void dijkstra()
{
	priority_queue<node> q;
	for(ll i=1;i<=3*n;i++) dis[i]=inf,vis[i]=0;
	dis[1]=0;
	q.push((node){1,0});
	while(!q.empty())
	{
		node u=q.top();
		q.pop();
		if(vis[u.id]) continue;
		vis[u.id]=1;
		for(ll i=0;i<e[u.id].size();i++)
		{
			ll to=e[u.id][i].to,w=e[u.id][i].w;
			if(dis[to]>dis[u.id]+w)
			{
				dis[to]=dis[u.id]+w;
				q.push((node){to,dis[to]});
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
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		if(d==0)
		{
			e[a].push_back((edge){b,c});
			e[b].push_back((edge){a,c});
			e[a+n].push_back((edge){b+n,c});
			e[b+n].push_back((edge){a+n,c});
			e[a+2*n].push_back((edge){b+2*n,c});
			e[b+2*n].push_back((edge){a+2*n,c});
		}	
		else
		{
			e[a].push_back((edge){b+n,c});
		    e[b].push_back((edge){a+n,c});
		    e[a+n].push_back((edge){b+2*n,c});
		    e[b+n].push_back((edge){a+2*n,c});
		}				
	}
	dijkstra();
	cout<<dis[n]-min(dis[2*n],dis[3*n]);
	return 0;
}
