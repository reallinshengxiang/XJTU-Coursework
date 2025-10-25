#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6,INF=-0x3f3f3f3f;
ll head[N],n,m,cnt,inq[N],dis[N],neg[N],pre[N];
struct Edge{
	ll to,next,w;
};
Edge edge[N];
void addedge(ll u,ll v,ll w)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
ll spfa(ll s)
{
	memset(neg,0,sizeof(neg));
	neg[s]=1;
	for(ll i=1;i<=n;i++)
	{
		dis[i]=INF;
		inq[i]=0;
	}
	dis[s]=0;
	queue<ll> q;
	q.push(s);
	inq[s]=1;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		inq[u]=0;
		for(ll i=head[u];i!=0;i=edge[i].next)
		{
			ll v=edge[i].to,w=edge[i].w;
			if(dis[u]+w>dis[v])
			{
				dis[v]=dis[u]+w;
				if(!inq[v])
				{
					inq[v]=1;
					q.push(v);
					neg[v]++;
					if(neg[v]>n) return 1;
				}
			}
		}
	}
	return 0;
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
		addedge(u,v,w);
	}
	ll kk=spfa(1);
	if(dis[n]==INF||kk==1) cout<<"AquaMoon is beautiful";
	else cout<<dis[n];
	return 0;
}
