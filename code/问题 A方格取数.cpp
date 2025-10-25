#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=18;
ll n,m,b[1<<N],dp[N][1<<N],a[N][N],cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n)
	{
		memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++) cin>>a[i][j];
		}
		cnt=0;
		for(ll i=0;i<=(1<<n)-1;i++)
		{
			if(!(i&(i<<1)))
			{
				cnt++;
				b[cnt]=i;
			}
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=cnt;j++)
			{
				ll sum=0;
				for(ll k=1;k<=n;k++)
				{
					if(b[j]&(1<<(k-1))) sum=sum+a[i][k];
				}
				dp[i][j]=sum;
				for(ll k=1;k<=cnt;k++)
				{
					if(!(b[j]&b[k])) dp[i][j]=max(dp[i][j],dp[i-1][k]+sum);
				}
			}
		}
		ll ans=0;
		for(ll i=1;i<=cnt;i++) ans=max(ans,dp[n][i]);
		cout<<ans<<"\n"; 
	}
	return 0;
} 
