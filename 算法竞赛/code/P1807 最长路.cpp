#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=-0x3f3f3f3f3f3f3f,N=2e3+10,M=5e4+10;
ll n,m,head[N],dis[N],cnt,neg[N],inq[N];
struct Edge{
	ll to,next,w;
};
Edge edge[M];
void init()
{
	for(ll i=0;i<=N-1;i++) head[i]=-1;
	for(ll i=0;i<=M-1;i++) edge[i].next=-1;
}
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
		dis[i]=inf;
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
		for(ll i=head[u];~i;i=edge[i].next)
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
	init();
	for(ll i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	spfa(1);
    if(dis[n]<=inf) cout<<"-1";
    else cout<<dis[n];
	return 0;
}
