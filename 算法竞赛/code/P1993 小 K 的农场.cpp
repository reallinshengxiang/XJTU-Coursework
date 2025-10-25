#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=0x3f3f3f3f3f3f;
const ll N=5e3+10,M=2e4+10;
ll n,m,head[N],cnt,dis[N],inq[N],neg[N];
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
	init();
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll opt,a,b,c;
		cin>>opt;
		if(opt==1)
		{
			cin>>a>>b>>c;
			addedge(a,b,-c);
		}
		else if(opt==2)
		{
			cin>>a>>b>>c;
			addedge(b,a,c);
		}
		else
		{
			cin>>a>>b;
			addedge(a,b,0);
			addedge(b,a,0);
		}
	}
	for(ll i=1;i<=n;i++) addedge(n+1,i,0);
	if(spfa(n+1)) cout<<"No";
	else cout<<"Yes";
	return 0;
}
