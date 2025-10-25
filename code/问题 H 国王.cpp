#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,f[11][1100][110],sum[1100],cnt,a[1100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=0;i<=(1<<n)-1;i++)
	{
		if((i&(i<<1))||(i&(i>>1))) continue;
		cnt++;
		a[cnt]=i;
		ll x=i;
		while(x) 
		{
			sum[cnt]=sum[cnt]+(x&1);
			x>>=1;
		}
	}
	for(ll i=1;i<=cnt;i++) f[1][i][sum[i]]=1;
	for(ll i=2; i<=n; i++)
	{
		for(ll j=1; j<=cnt; j++)
		{
			for(ll k=1; k<=cnt; k++)
			{
				if((a[j]&a[k])||((a[j]>>1)&a[k])||((a[j]<<1)&a[k])) continue;
	            for(int ii=sum[j]+sum[k];ii<=m;ii++) f[i][j][ii]=f[i][j][ii]+f[i-1][k][ii-sum[j]];
			}
		}
	}
	ll ans=0;
	for(ll i=1; i<=cnt; i++)
	{
		ans=ans+f[n][i][m];
	}
	cout<<ans;
	return 0;
}
