#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
vector<ll> e[N];
ll n,m,k,maxx,maxxid,dis[N],vis[N];
void bfs(ll x)
{
	deque<ll> dq;
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	vis[x]=1;
	dq.push_back(x);
	while(!dq.empty())
	{
		ll p=dq.front();
		dq.pop_front();
	//	cout<<x<<"  "<<p<<"  "<<dis[p]<<"\n";
		for(ll i=0;i<e[p].size();i++)
		{
			ll y=e[p][i];
			if(vis[y]) continue;
			vis[y]=1;
			dis[y]=dis[p]+1;
			dq.push_back(y);
			if(maxx<dis[y])
			{
				maxx=dis[y];
				maxxid=y;
			}
			else if(maxx==dis[y]&&y<maxxid) maxxid=y;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	while(k--)
	{
		ll x;
		cin>>x;		
		maxx=0;
		maxxid=n+1;
		bfs(x);
		if(maxxid==n+1) maxxid=0;
		cout<<maxxid<<"\n";
	}
	return 0;
}
