#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e4+10;
ll ans=-2147483647,dp[N],a[N],n;
vector<ll> edge[N]; 
ll dfs(ll x,ll father)
{
	dp[x]=a[x];
	for(ll i=0;i<edge[x].size();i++)
	{
		ll y=edge[x][i];
		if(y==father) continue;
		dfs(y,x);
		if(dp[y]>0) dp[x]=dp[x]+dp[y];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n-1;i++)
	{
		ll x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x); 
	}
	dfs(1,0);
	for(ll i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
