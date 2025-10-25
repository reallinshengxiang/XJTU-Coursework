#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][110],num[15],n,m,mod;
int vs[20][110],idx;
ll dfs(ll pos,ll last,ll lead,ll limit)
{
	if(pos==0) 
	{
		if(last%mod==0) return 1;
		else return 0;
	} 	
	if(!limit&&!lead&&dp[pos][last]!=-1) return dp[pos][last%mod];
	ll ans=0;
	ll up=9;
	if(limit) up=num[pos];
	for(ll i=0;i<=up;i++)
	{
		if(lead&&i==0) ans=ans+dfs(pos-1,0,1,limit&&i==up);
		else ans=ans+dfs(pos-1,(last+i)%mod,0,limit&&i==up);
	}
	if(!lead&&!limit) dp[pos][last]=ans;
	return ans;
}
ll solve(ll x)
{
	idx++; 
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
	ll n,m;
	while(cin>>n>>m>>mod)
	{
		cout<<solve(m)-solve(n-1)<<"\n";
	}	
	return 0;
}
