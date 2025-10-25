#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=100003,N=1e6+10;
vector<ll> edge[N];
ll ans[N],n,m,dis[N],vis[N];
void spfa(ll st)
{
	queue<ll> que;
	dis[st]=0;
	vis[st]=1;
	que.push(st);
	ans[st]=1;
	while(!que.empty())
	{
		ll x=que.front();
		que.pop();
		for(ll i=0;i<edge[x].size();i++)
		{
			ll y=edge[x][i];
			if(!vis[y])
			{
				vis[y]=1;
				que.push(y);
				dis[y]=dis[x]+1;
			}
			if(dis[y]==dis[x]+1) ans[y]=(ans[y]+ans[x])%mod;
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
		ll x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	spfa(1);
	for(ll i=1;i<=n;i++) cout<<ans[i]<<"\n";
	return 0;
}
