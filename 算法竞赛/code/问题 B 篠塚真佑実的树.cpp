#include<bits/stdc++.h>
using namespace std;
#define ll int
ll f[2020][2020],q,ans,s,t,n,m,u,v,w,men[200020];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(f,0x7f/3,sizeof(f));
	for(ll i=1;i<=n;i++) f[i][i]=0;
	for(ll i=1;i<=m;i++) cin>>men[i];
	for(ll i=1;i<=n-1;i++) 
	{
		cin>>u>>v>>w;
		f[u][v]=f[v][u]=w;
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>s>>t;
		ans=f[s][t];
		for(ll i=1;i<=m;i++) 
		{
			for(ll j=1;j<=m;j++)  ans=min(min(ans,f[s][men[i]]+f[men[j]][t]),f[s][men[j]]+f[men[i]][t]);
		}
		cout<<ans<<"\n"; 
	}
	return 0;
 } 
