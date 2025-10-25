#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[15][15],num[15];
ll dfs(ll pos,ll last,ll lead,ll limit)
{
	ll ans=0;
	if(pos==0) return 1;
	if(!lead&&!limit&&dp[pos][last]!=-1) return dp[pos][last];
	ll up;
	if(limit) up=num[pos];
	else up=9;
	for(ll i=0;i<=up;i++)
	{
		if(i<last) continue;
		if(lead&&i==0) ans=ans+dfs(pos-1,-1,1,limit&&i==up);
		else ans=ans+dfs(pos-1,i,0,limit&&i==up);
	} 
	if(!limit&&!lead) dp[pos][last]=ans;
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
	return dfs(len,-1,1,1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a,b;
	while(cin>>a>>b)
	{
		cout<<solve(b)-solve(a-1)<<"\n";
	}
	return 0; 
}
