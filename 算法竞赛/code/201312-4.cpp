#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod=1000000007,N=1e3+10;
ll dp[N][10],n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	dp[1][0]=1;
	for(ll i=2;i<=n;i++)
	{
		dp[i][0]=1;
		dp[i][1]=(dp[i-1][1]*2%mod+dp[i-1][0]%mod)%mod;
		dp[i][2]=(dp[i-1][2]%mod+dp[i-1][0]%mod)%mod;
		dp[i][3]=(dp[i-1][3]*2%mod+dp[i-1][1]%mod)%mod;
		dp[i][4]=(dp[i-1][4]*2%mod+dp[i-1][2]%mod+dp[i-1][1]%mod)%mod;
		dp[i][5]=(dp[i-1][5]*2%mod+dp[i-1][4]%mod+dp[i-1][3]%mod)%mod;
	}
	cout<<dp[n][5];
	return 0;
}
