#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll dp[20][220],num[20];
ll dfs(ll pos,ll sum,ll limit)
{
	ll ans=0;
	if(pos==0) return sum;
	if(!limit&&dp[pos][sum]!=-1) return dp[pos][sum];
	ll up=9;
	if(limit) up=num[pos];
	for(ll i=0;i<=up;i++)
	{
		ans=(ans+dfs(pos-1,sum+i,i==up&&limit))%mod;
	}
	if(!limit) dp[pos][sum]=ans%mod;
	return ans%mod; 
} 
ll solve(ll x)
{
	ll ans=0,len=0;
	while(x)
	{
		len++;
		num[len]=x%10;
		x=x/10;
	}
	memset(dp,-1,sizeof(dp));
	return dfs(len,0,1)%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,l,r;
	cin>>T;
	while(T--)
	{
		cin>>l>>r;
		cout<<(solve(r)-solve(l-1)+mod)%mod<<"\n";
	}
	return 0;
}
