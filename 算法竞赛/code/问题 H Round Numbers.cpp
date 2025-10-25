#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=35;
ll dp[N][N][N],num[N];
ll dfs(ll pos,ll num0,ll num1,ll lead,ll limit)
{
	ll ans=0;
	if(pos==0) 
	{
		if(lead||num0>=num1) return 1;
		else return 0;
	}
	if(!lead&&!limit&&dp[pos][num0][num1]!=-1) return dp[pos][num0][num1];
	ll up;
	if(limit) up=num[pos];
	else up=1;
	for(ll i=0;i<=up;i++)
	{
		if(lead&&i==0) ans=ans+dfs(pos-1,0,0,1,limit&&i==up);
		else
		{
			if(i) ans=ans+dfs(pos-1,num0,num1+1,0,limit&&i==up);
			else ans=ans+dfs(pos-1,num0+1,num1,0,limit&&i==up); 
		}
	}
	if(!lead&&!limit) dp[pos][num0][num1]=ans;
	return ans;
}
ll solve(ll x)
{
	ll len=0;
	while(x)
	{
		len++;
		num[len]=(x&1);
		x>>=1;
	}
	memset(dp,-1,sizeof(dp));
	return dfs(len,0,0,1,1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll l,r;
	cin>>l>>r;
	cout<<solve(r)-solve(l-1);
	return 0;
}
