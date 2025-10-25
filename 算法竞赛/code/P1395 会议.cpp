#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e4+10;
vector<ll> e[N];
ll siz[N],n,x,y,f[N],dis[N];
void dfs1(ll now)
{
	siz[now]=1;
	for(ll i=0;i<e[now].size();i++)
	{
		ll to=e[now][i];
		if(dis[to]) continue;
		dis[to]=dis[now]+1;
		dfs1(to);
		siz[now]=siz[now]+siz[to];
	}
}
void dfs(ll now,ll fa)
{
	f[now]=f[fa]+n-2*siz[now];
	for(ll i=0;i<e[now].size();i++)
	{
		ll to=e[now][i];
		if(to==fa) continue;
		dfs(to,now);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}	
	dis[1]=1;
	dfs1(1);
	
	y=-n;
	for(ll i=1;i<=n;i++) y=y+dis[i];
	f[1]=y;
	x=1;
	for(ll i=0;i<e[1].size();i++)
	{
		ll to=e[1][i];
		dfs(to,1);
	}
	
	for(ll i=2;i<=n;i++) 
	{
		if(f[i]<y) y=f[i],x=i;
	}
	cout<<x<<" "<<y;
	return 0;
}
