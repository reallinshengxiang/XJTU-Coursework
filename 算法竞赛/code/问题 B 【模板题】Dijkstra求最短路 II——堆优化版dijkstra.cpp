#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=0x3f3f3f3f3f3f;
const ll N=3e5+10;
struct edge{
	ll from,to,w;
};
vector<edge> e[N];
struct node{
	ll id,ndis;
	bool operator<(const node&a) const
	{
		return ndis>a.ndis;
	}
};
ll n,m,dis[N],done[N];
void dijkstra()
{
	ll s=1;
	for(ll i=1;i<=n;i++) dis[i]=inf,done[i]=0;
	dis[s]=0;
	priority_queue<node> q;
	q.push((node){s,dis[s]});
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
			if(dis[y.to]>y.w+u.ndis)
			{
				dis[y.to]=y.w+u.ndis;
				q.push((node){y.to,dis[y.to]});
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
		ll x,y,z;
		cin>>x>>y>>z;
		e[x].push_back((edge){x,y,z});
	}
	dijkstra();
	if(dis[n]>=inf) cout<<"-1";
	else cout<<dis[n];
	return 0;
}
