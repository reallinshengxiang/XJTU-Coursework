#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=35;
ll n,m,dp[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n%2==0&&m%2==0)
	{
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=m;i++) dp[1][i]=1;
	for(ll i=2;i<=n;i++)
	{
		dp[i][1]=1;
		for(ll j=2;j<=m;j++)
		{
			if(i%2==0&&j%2==0) continue;
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	cout<<dp[n][m];
	return 0;
}
