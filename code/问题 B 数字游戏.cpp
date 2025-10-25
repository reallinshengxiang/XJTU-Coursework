#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][110],num[15],a,b;
ll dfs(ll pos,ll last,ll lead,ll limit)
{
	if(pos==0) return 1;
	if(!lead&&!limit&&dp[pos][last]!=-1) return dp[pos][last];
	ll up=9,ans=0;
	if(limit) up=num[pos];
	for(ll i=last;i<=up;i++)
	{
		if(lead&&i==0) ans=ans+dfs(pos-1,0,1,limit&&i==up);
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
	return dfs(len,0,1,1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>a>>b)
	{
		cout<<solve(b)-solve(a-1)<<"\n";
	}
	return 0;
}
