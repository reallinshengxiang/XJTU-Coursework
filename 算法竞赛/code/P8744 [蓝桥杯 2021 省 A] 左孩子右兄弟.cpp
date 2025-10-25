#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll num[N],n,dp[N];
vector<ll> e[N]; 
void dfs(ll x)
{
	ll size=0;
	for(ll i=0;i<e[x].size();i++)
	{
		ll y=e[x][i];
		dfs(y);
		size++;
		dp[x]=max(dp[x],dp[y]);
	}
	dp[x]=dp[x]+size;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n;
	for(ll i=2;i<=n;i++)
	{
		ll x;
		cin>>x;
		e[x].push_back(i);
	} 
	dfs(1);
	cout<<dp[1];
	return 0; 
}
