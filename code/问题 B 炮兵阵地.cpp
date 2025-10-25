#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[110][130][130],a[110],b[110],sum[110],n,m,cnt;
char ch;
ll count(ll x)
{
	ll num=0,i=1;
	while(i<=x)
	{
		if(x&i) num++;
		i<<=1;
	}
	return num;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='H') a[i]=a[i]+(1<<(m-j));
		}
	}
	for(ll i=0;i<=(1<<m)-1;i++)
	{
		if(!(i&(i<<1))&&!(i&(i>>1))&&!(i&(i>>2))&&!(i&(i<<2)))
		{
			cnt++;
			b[cnt]=i;
			sum[cnt]=count(i);
		}
	}
	for(ll i=1;i<=cnt;i++)
	{
		if(!(a[1]&b[i])) dp[1][i][0]=sum[i];
	}
	for(ll i=1;i<=cnt;i++)
	{
		if(!(a[2]&b[i]))
		{
			for(ll j=1;j<=cnt;j++)
			{
				if(!(b[i]&b[j])) dp[2][i][j]=max(dp[2][i][j],dp[1][j][0]+sum[i]);
			}
		}
	}
	for(ll i=3;i<=n;i++)
	{
		for(ll j=1;j<=cnt;j++)
		{
			if(a[i]&b[j]) continue;
			for(ll k=1;k<=cnt;k++)
			{
				if((b[k]&a[i-1])||(b[k]&b[j])) continue;
				for(ll t=1;t<=cnt;t++)
				{
					if((b[t]&a[i-2])||(b[t]&b[k])||(b[t]&b[j])) continue;
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][t]+sum[j]);				
				}
				
			}
		}
	}
	ll ans=0;
	for(ll i=1;i<=cnt;i++)
	{
		for(ll j=1;j<=cnt;j++) ans=max(ans,dp[n][i][j]);
	}
	cout<<ans;
	return 0; 
}
