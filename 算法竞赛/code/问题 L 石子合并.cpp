#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=0x3f3f3f3f;
ll dp[310][310],sum[310][310],a[310],n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		dp[i][i]=0;
		sum[i][i]=a[i];
		for(ll j=i+1;j<=n;j++) sum[i][j]=sum[i][j-1]+a[j];
	}	
	for(ll len=2;len<=n;len++)
	{
		for(ll i=1;i<=n-len+1;i++)
		{
			ll j=i+len-1;
			dp[i][j]=inf;
			for(ll k=i;k<=j-1;k++)  dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[i][j]);
		}
	}
	cout<<dp[1][n];
	return 0;	
}
