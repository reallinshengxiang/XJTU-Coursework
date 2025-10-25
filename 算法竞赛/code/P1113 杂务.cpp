#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll dp[N],n,x,y,len[N],ans;
vector<ll> edge[N];
ll dfs(ll x)
{
	if(dp[x]) return dp[x];
	for(ll i=0;i<edge[x].size();i++)
	{
		ll y=edge[x][i];
		ll xx=dfs(y);
		dp[x]=max(dp[x],xx);
	}
	dp[x]=dp[x]+len[x];
	return dp[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x>>len[i];
		while(cin>>y)
		{
			if(y==0) break;
			edge[y].push_back(x);
		}
	}
	for(ll i=1;i<=n;i++) ans=max(ans,dfs(i));
	cout<<ans;
	return 0;
}
