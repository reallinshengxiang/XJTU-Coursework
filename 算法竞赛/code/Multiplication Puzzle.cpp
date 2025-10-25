#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll dp[N][N],p[N],INF,n;
ll solve(ll l,ll r)
{
	if(l+1==r)
	{
		dp[l][r]=0;
		return dp[l][r];
	}
	if(l+2==r)
	{
		dp[l][r]=p[l]*p[l+1]*p[r];
		return dp[l][r];
	}
	if(dp[l][r]!=INF) return dp[l][r];
	for(ll i=l+1;i<r;i++) dp[l][r]=min(dp[l][r],solve(l,i)+solve(i,r)+p[l]*p[i]*p[r]);
	return dp[l][r];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,0x3f,sizeof(dp));
	INF=dp[0][0];
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>p[i];
	solve(1,n);
	cout<<dp[1][n];
	return 0;
}
