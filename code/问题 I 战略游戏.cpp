#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Edge{
	ll next,to;
};
Edge edge[3010];
ll dp[1510][1510],head[1510],vis[1510],n,ii,k,rr,cnt;
void add_edge(ll x,ll y)
{
	cnt++;
	edge[cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void dfs(ll x)
{
	vis[x]=1;
	dp[x][1]=1;
	for(ll i=head[x];i;i=edge[i].next)
	{
		ll y=edge[i].to;
		if(vis[y]==1) continue;
		dfs(y);
		dp[x][1]=dp[x][1]+min(dp[y][0],dp[y][1]);
		dp[x][0]=dp[x][0]+dp[y][1];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>ii>>k;
		while(k--)
		{
			
			cin>>rr;
			add_edge(ii,rr);
			add_edge(rr,ii);
		}
	}
	dfs(0);
	cout<<min(dp[0][1],dp[0][0]);
	return 0;
 } 
