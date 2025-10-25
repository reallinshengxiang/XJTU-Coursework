#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=550;
ll n,dp[N][N],a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	memset(dp,0x3f,sizeof(dp));
	for(ll i=1;i<=n;i++) cin>>a[i],dp[i][i]=1;
	for(ll i=1;i<=n-1;i++)
	{
		if(a[i]==a[i+1]) dp[i][i+1]=1;
		else dp[i][i+1]=2;
	}
	for(ll len=3;len<=n;len++)
	{
		for(ll i=1;i+len-1<=n;i++)
		{
			ll j=i+len-1;
			if(a[i]==a[j]) dp[i][j]=dp[i+1][j-1];
			for(ll k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
		}
	}
	cout<<dp[1][n];
	return 0;
}
