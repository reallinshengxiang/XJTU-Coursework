#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][10],num[10],n,m;
ll dfs(ll pos,ll last,ll limit)
{
	if(pos==0)  return 1;
	if(!limit&&dp[pos][last]!=-1) return dp[pos][last];
	ll ans=0;
	ll up=9;
	if(limit) up=num[pos];
	for(ll i=0;i<=up;i++)
	{
		if(i==4||(i==2&&last==6)) continue;
		ans=ans+dfs(pos-1,i,limit&&i==up);
	}
	if(!limit) dp[pos][last]=ans;
	return ans;
}
ll solve(ll x)
{
	ll len=0;
	while(x)
	{
		len++;
		num[len]=x%10;
		x=x/10;
	}
	memset(dp,-1,sizeof(dp));
	return dfs(len,0,1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		cout<<solve(m)-solve(n-1)<<"\n";
	}
	return 0;
}
