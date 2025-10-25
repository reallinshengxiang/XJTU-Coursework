#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=0x3f3f3f3f3f3f;
const ll N=2e3+10,M=6e3+10;
ll n,m,T,head[N],cnt,dis[N],inq[N],neg[N];
struct Edge{
	ll to,next,w;
};
Edge edge[M];
void init()
{
	for(ll i=0;i<=N-1;i++) head[i]=-1;
	for(ll i=0;i<=M-1;i++) edge[i].next=-1;
	cnt=0;
}
void addedge(ll u,ll v,ll w)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
ll spfa(ll st)
{
	memset(neg,0,sizeof(neg));
	neg[st]=1;
	for(ll i=1;i<=n;i++)
	{
		dis[i]=inf;
		inq[i]=0;
	}
	dis[st]=0;
	queue<ll> que;
	que.push(st);
	inq[st]=1;
	while(!que.empty())
	{
		ll u=que.front();
		que.pop();
		inq[u]=0;
		for(ll i=head[u];~i;i=edge[i].next)
		{
			ll v=edge[i].to,w=edge[i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				if(!inq[v])
				{
					inq[v]=1;
					que.push(v);
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
	cin>>T;
	while(T--)
	{
		init();
		cin>>n>>m;
		for(ll i=1;i<=m;i++)
		{
			ll u,v,w;
			cin>>u>>v>>w;
			addedge(u,v,w);
			if(w>=0) addedge(v,u,w);
		}
		if(spfa(1)) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
