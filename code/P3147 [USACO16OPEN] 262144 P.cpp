#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=263144;
ll a,n,dp[60][N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a;
		dp[a][i]=i+1;
	}
	for(ll i=2;i<=58;i++)
	{
		for(ll j=1;j<=n;j++) 
		{
			if(!dp[i][j]) dp[i][j]=dp[i-1][dp[i-1][j]];
			if(dp[i][j]) ans=i;
		}
	}
	cout<<ans;
	return 0;
 } 
