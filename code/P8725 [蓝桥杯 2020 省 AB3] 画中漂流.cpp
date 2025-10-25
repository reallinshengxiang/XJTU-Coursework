#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll d,t,m,dp[3010][1515];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>d>>t>>m;
	dp[0][0]=1;
	for(ll i=1;i<=t;i++)
	{
		if(i<d) dp[i][0]=1;
		for(ll j=1;j<=m;j++)
		{
			if(i-2*j>=d) continue;
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
		}
	}
	cout<<dp[t][m];
	return 0;
}
