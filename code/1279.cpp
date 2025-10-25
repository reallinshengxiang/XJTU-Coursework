#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
const ll N=1010;
ll sum1[N][N],sum2[N][N],a[N][N],maxx=-1e9,n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>a[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) sum1[i][j]=sum1[i-1][j]+a[i][j],sum2[i][j]=sum2[i][j-1]+a[i][j];
	}
	for(ll len=2;len<=min(n,m);len++)
	{
	    for(ll x=1;x+len-1<=n;x++)
		{
		    for(ll y=1;y+len-1<=m;y++)
			{
				maxx=max(maxx,sum1[x+len-1][y]-sum1[x-1][y]+sum1[x+len-1][y+len-1]-sum1[x-1][y+len-1]+sum2[x][y+len-2]-sum2[x][y]+sum2[x+len-1][y+len-2]-sum2[x+len-1][y]);
			} 
	    }	
	}
	cout<<maxx;
	return 0;
} 
