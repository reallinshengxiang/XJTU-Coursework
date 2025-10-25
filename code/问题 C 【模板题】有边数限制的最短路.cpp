#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
struct Edge{
	ll u,v,w;
};
Edge edge[N];
ll ans,d[550],dis[550],inf,n,m,k;
ll bellman()
{
	ll s=1;
	memset(dis,0x3f,sizeof(dis));
	inf=dis[0];
	dis[s]=0;
	for(ll kk=1;kk<=k;kk++)
	{
		memcpy(d,dis,sizeof(dis));
		for(ll i=1;i<=m;i++)
		{
			ll u=edge[i].u,v=edge[i].v,w=edge[i].w;
			dis[v]=min(dis[v],d[u]+w);
		}
	}
	if(dis[n]==inf) return -1;
	else return dis[n];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	ans=bellman();
	if(ans==-1) cout<<"impossible";
	else cout<<ans;
	return 0;
}
