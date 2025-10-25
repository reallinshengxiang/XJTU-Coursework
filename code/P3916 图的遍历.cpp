#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll dp[N],n,m,x,y;
vector<ll> edge[N];
void dfs(ll x,ll st)
{
	if(dp[x]) return;
	dp[x]=st;
	for(ll i=0;i<edge[x].size();i++)  dfs(edge[x][i],st);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y;
		edge[y].push_back(x);
	}
	for(ll i=n;i>=1;i--) dfs(i,i);
	for(ll i=1;i<=n;i++) cout<<dp[i]<<" "; 
	return 0;
}
