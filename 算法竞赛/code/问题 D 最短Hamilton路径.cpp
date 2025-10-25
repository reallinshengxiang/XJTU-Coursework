#include<bits/stdc++.h>
using namespace std;
#define ll int
ll dp[1<<20][20],a[20][20],n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=0;i<=n-1;i++)
	{
		for(ll j=0;j<=n-1;j++) cin>>a[i][j];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1][0]=0;
	for(ll i=1;i<(1<<n);i++)
	{
		for(ll j=0;j<=n-1;j++)
		{
			for(ll k=0;k<=n-1;k++)  
			{
				if((i>>j&1)&&(i>>k&1))  dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k]+a[k][j]);
			}
		}
	}
	cout<<dp[(1<<n)-1][n-1];
	return 0;
}
