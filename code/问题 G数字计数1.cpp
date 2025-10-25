#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=15;
ll dp[N][N][2][2],num[N],now,a,b;
ll dfs(ll pos,ll sum,ll lead,ll limit)
{
	ll ans=0;
	if(pos==0) return sum;
	if(dp[pos][sum][limit][lead]!=-1) return dp[pos][sum][limit][lead];
	ll up=9;
	if(limit) up=num[pos];
	for(ll i=0;i<=up;i++)
	{
		if(i==0&&lead) ans=ans+dfs(pos-1,sum,1,limit&&i==up);
		else if(i==now) ans=ans+dfs(pos-1,sum+1,0,limit&&i==up);
		else if(i!=now) ans=ans+dfs(pos-1,sum,0,limit&&i==up);
	}
	dp[pos][sum][limit][lead]=ans;
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
	return dfs(len,0,1,1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	for(ll i=0;i<=9;i++)
	{
		now=i;
		cout<<solve(b)-solve(a-1)<<" ";
	}
	return 0;
}
