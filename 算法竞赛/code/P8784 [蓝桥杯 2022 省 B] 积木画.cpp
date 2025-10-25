#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll mod=1000000007,N=1e7+10;
ll dp[N],f[N],n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	dp[1]=1;
	dp[2]=2;
	f[1]=1;
	f[2]=2;
	for(ll i=3;i<=n;i++)
	{
		dp[i]=(dp[i-1]%mod+(dp[i-2]%mod+2*f[i-2]%mod)%mod)%mod;
		f[i]=(dp[i-1]%mod+f[i-1]%mod)%mod;
	}
	cout<<dp[n];
	return 0;
}
//10000000  669978939

