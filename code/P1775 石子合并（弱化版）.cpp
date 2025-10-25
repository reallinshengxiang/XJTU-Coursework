#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=330;
ll dp[N][N],n,sum[N],a[N],inf;
ll dfs(ll l,ll r)
{
	if(l>=r) return 0;
	if(dp[l][r]!=inf) return dp[l][r];
	for(ll k=l;k<=r-1;k++) dp[l][r]=min(dp[l][r],dfs(l,k)+dfs(k+1,r)+sum[r]-sum[l-1]);
	return dp[l][r];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	memset(dp,127,sizeof(dp));
	inf=dp[0][0];
	dfs(1,n);
	cout<<dp[1][n];
	return 0;
}
