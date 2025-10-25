#include<bits/stdc++.h>
using namespace std;
#define ll long long
double ans,dp[2010][2010],p;
ll n,t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>t>>p;
	dp[0][0]=1;
	for(ll i=1;i<=t;i++)
	{
		dp[i][0]=dp[i-1][0]*(1.0-p);
		for(ll j=1;j<=n-1;j++) dp[i][j]=dp[i-1][j]*(1.0-p)+dp[i-1][j-1]*p;
		dp[i][n]=dp[i-1][n]+dp[i-1][n-1]*p;
	}
	for(ll i=1;i<=n;i++) 	ans=ans+dp[t][i]*i;
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
} 
