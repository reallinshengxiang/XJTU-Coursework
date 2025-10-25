#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll edge[310],f[310][310],p,h[310],cnt,nex[310],n,m;
void add_edge(ll a,ll b)
{
	edge[cnt]=b;
	nex[cnt]=h[a];
	h[a]=cnt;
	cnt++;
}
ll dfs(ll u)
{
	ll num=1;
	for(ll i=h[u];i>=0;i=nex[i])
	{
		ll v=edge[i];
		ll t=dfs(v);
		num=num+t;
		for(ll j=num;j>=0;j--)
		{
			for(ll k=0;k<j&&k<=t;k++)  f[u][j]=max(f[u][j],f[u][j-k]+f[v][k]);
		}
	}
	return num;
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
	cin>>n>>m;
	memset(h,-1,sizeof(h));
	for(ll i=1;i<=n;i++)
	{
		cin>>p>>f[i][1];
		add_edge(p,i);
	}
	dfs(0);	
	cout<<f[0][m+1];
	return 0;
}
