#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll ans,num[N],dp[10][1100][N],b[N],cnt,n,kk;
ll count(ll x)
{
	ll ans=0,i=1;
	while(i<=x)
	{
		if(x&i) ans++;
		i<<=1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>kk;
	for(ll i=0;i<=(1<<n)-1;i++)
	{
		if(!((i<<1)&i)&&!((i>>1)&i))
		{
			cnt++;
			b[cnt]=i;
			num[cnt]=count(i);
		}
	}
	dp[0][0][0]=1;
	for(ll i=1;i<=cnt;i++)	dp[1][num[i]][i]=1;
	for(ll i=2;i<=n;i++)
	{
		for(ll j=1;j<=cnt;j++)
		{
			for(ll k=1;k<=cnt;k++)
			{
				if(b[j]&(b[k]<<1|b[k]|b[k]>>1)) continue;
				for(ll t=0;t<=kk;t++)
				{
					if(t-num[j]>=0)		dp[i][t][j]=dp[i][t][j]+dp[i-1][t-num[j]][k];
				}
			}
		}
	}
	for(ll i=1;i<=cnt;i++) ans=ans+dp[n][kk][i];
	cout<<ans;
	return 0;
}
