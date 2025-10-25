#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
vector<ll> e[N];
deque<ll> q;
ll n,m,u,v,p,vis[N];
void bfs()
{
	q.push_back(1);
	vis[1]=1;
	while(!q.empty())
	{
		p=q.front();
		q.pop_front();
		cout<<p<<" ";
		for(ll i=0;i<e[p].size();i++) 
		{
			if(!vis[e[p][i]]) q.push_back(e[p][i]);
			vis[e[p][i]]=1;
		}
	}
	return;
}
void dfs(ll now)
{
	vis[now]=1;
	for(ll i=0;i<e[now].size();i++)
	{
		if(vis[e[now][i]]) continue;
		cout<<e[now][i]<<" ";
		dfs(e[now][i]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>u>>v;
		e[u].push_back(v);
	}
	for(ll i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
	cout<<1<<" ";
	dfs(1);
	cout<<"\n";
	memset(vis,0,sizeof(vis));
	bfs();
	return 0;
}
