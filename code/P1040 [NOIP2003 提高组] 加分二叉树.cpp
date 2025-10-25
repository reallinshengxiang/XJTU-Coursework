#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=33;
ll dp[33][33],root[33][33],a[33],n;
ll dfs(ll l,ll r)
{
	if(l>r) return 1;
	if(l==r)
	{
		dp[l][r]=a[l];
		return dp[l][r];
	}
	if(dp[l][r]!=-1) return dp[l][r];
	ll maxx;
	for(ll i=l;i<=r;i++)
	{
		ll jf=dfs(l,i-1)*dfs(i+1,r)+a[i];
		if(jf>dp[l][r])
		{
			dp[l][r]=jf;
			root[l][r]=i;
			maxx=jf;
		}
	}
	return maxx;
}
void print(ll l,ll r)
{
	if(l>r) return;
	cout<<root[l][r]<<" ";
	print(l,root[l][r]-1);
	print(root[l][r]+1,r);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++) root[i][i]=i;
	memset(dp,-1,sizeof(dp));
	dfs(1,n);
	cout<<dp[1][n]<<"\n";
	print(1,n);
	return 0;
} 
