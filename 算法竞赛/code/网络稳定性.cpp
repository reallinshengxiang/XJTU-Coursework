#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=100000000;
ll n,m,q,f[5050][5050],x,y,u,v,w,a[5050][5050];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	memset(f,125/3,sizeof(f));
	memset(a,125/3,sizeof(a));
	for(ll i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		f[u][v]=f[v][u]=w;
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			if(i!=k)
			for(ll j=1;j<=n;j++)
			{
				if(j!=k&&a[i][k]<inf&&f[k][j]<inf) a[i][j]=a[j][i]=min(min(f[i][j],f[i][k]),f[k][j]);
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	while(q--)
	{
		cin>>x>>y;
		if(f[x][y]>inf) cout<<"-1\n";
		else cout<<a[x][y]<<"\n";
	}
	return 0;
}
