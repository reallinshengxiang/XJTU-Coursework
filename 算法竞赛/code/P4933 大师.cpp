#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll x=2e4+10,N=1e3+10,M=4e4+20,mod=9982443539;
int h[N],vis[N][M],dp[N][M];
ll ans,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>h[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i-1;j>=1;j--)
		{
			if(!vis[j][h[j]-h[i]+x])
			{
				dp[j][h[j]-h[i]+x]++;
				vis[j][h[j]-h[i]+x]=1;
			}
			ans=(ans+dp[j][h[j]-h[i]+x])%mod;
			dp[i][h[j]-h[i]+x]=(dp[i][h[j]-h[i]+x]+dp[j][h[j]-h[i]+x])%mod;
		}
	}
	cout<<ans+n;
	return 0;
}
