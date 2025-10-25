#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=220,M=5e4+10;
ll inf,dis[N][N],n,m,t[N],st[M],ed[M],day[M],vis[N],q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dis,127,sizeof(dis));
	inf=dis[0][0];
	cin>>n>>m;
	for(ll i=0;i<=n-1;i++) dis[i][i]=0;
	for(ll i=0;i<=n-1;i++) cin>>t[i];
	for(ll i=1;i<=m;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		dis[x][y]=dis[y][x]=z;
	}
	cin>>q;
	for(ll i=1;i<=q;i++) cin>>st[i]>>ed[i]>>day[i];
	for(ll ii=1;ii<=q;ii++)
	{
		for(ll k=0;k<=n-1;k++)
		{
			if(t[k]<=day[ii]&&!vis[k])
			{
				vis[k]=1;
				for(ll i=0;i<=n-1;i++)
			    {
				    if(i==k) continue;
				    for(ll j=0;j<=n-1;j++)
				    {
					   if(j==i||j==k) continue;
					   if(dis[i][k]<inf&&dis[k][j]<inf&&dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
				   }
			    }
			}
			
		}
		if(t[st[ii]]<=day[ii]&&t[ed[ii]]<=day[ii]&&dis[st[ii]][ed[ii]]<inf) cout<<dis[st[ii]][ed[ii]]<<"\n";
		else cout<<"-1\n";
	}
 	return 0;
} 
