#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[15][11][11][2][2][2],num[20];
ll dfs(ll pos,ll u,ll v,ll flag,ll n8,ll n4,ll limit)
{
	ll ans=0;
	if(n8&&n4) return 0;
	if(pos==0) return flag;
	if(!limit&&dp[pos][u][v][flag][n8][n4]!=-1) return dp[pos][u][v][flag][n8][n4];
	ll up=9;
	if(limit) up=num[pos];
	for(ll i=0;i<=up;i++)
	{
		ans=ans+dfs(pos-1,i,u,flag||(i==u&&i==v),n8||(i==8),n4||(i==4),limit&&(i==up));
	}
	if(!limit) dp[pos][u][v][flag][n8][n4]=ans;
	return ans;
}
ll solve(ll x)
{
	ll len=0,ans=0;
	while(x!=0)
	{
		len++;
		num[len]=x%10;
		x=x/10;
	}
	if(len!=11) return 0;
	memset(dp,-1,sizeof(dp));
	for(ll i=1;i<=num[len];i++) ans=ans+dfs(len-1,i,0,0,i==8,i==4,i==num[len]); 
	return ans;
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
