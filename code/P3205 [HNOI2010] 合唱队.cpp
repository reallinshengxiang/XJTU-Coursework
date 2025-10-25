#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=19650827,N=1010;
ll dp[N][N],n,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],dp[i][i]=1;
	for(ll len=2;len<=n;len++)
	{
		for(ll st=1;st+len-1<=n;st++)
		{
			ll ed=st+len-1;
			if(a[st]<a[st+1]) dp[ed][st]=(dp[ed][st]+dp[ed][st+1])%mod;
			if(a[st]<a[ed]&&ed!=st+1) dp[ed][st]=(dp[ed][st]+dp[st+1][ed])%mod;
			if(a[ed]>a[ed-1]) dp[st][ed]=(dp[st][ed]+dp[st][ed-1])%mod;
			if(a[ed]>a[st]&&ed!=st+1) dp[st][ed]=(dp[st][ed]+dp[ed-1][st])%mod;
		}
	}
	cout<<(dp[1][n]+dp[n][1])%mod;
	return 0;
}
