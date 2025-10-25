#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=100000000;
ll f[15][1<<12],ff[15],g[1<<12],h[1<<12],a[15][15],n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=n;j++) cin>>a[i][j];
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=n;j++) ff[i]=(ff[i]<<1)+a[i][j];
	}
	for(ll i=0;i<=(1<<n)-1;i++) 
	{
		if(!(i&(i>>1))&&!(i&(i<<1)))
		{
			g[i]=1;
			if((i&ff[1])==i) f[1][i]=1;
		}
	}
	for(ll i=2;i<=m;i++)
	{
		for(ll j=0;j<=(1<<n)-1;j++)
		{
			if(((j&ff[i-1])==j)&&g[j])
			{
				for(ll k=0;k<=(1<<n)-1;k++)
				{
					if(((k&ff[i])==k)&&g[k]&&!(j&k))	f[i][k]=(f[i][k]+f[i-1][j])%mod;
				}
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<=(1<<n)-1;i++) ans=(ans+f[m][i])%mod;
	cout<<ans;
    return 0;
}
