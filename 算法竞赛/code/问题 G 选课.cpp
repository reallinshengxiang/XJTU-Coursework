#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll v,w;
	node(ll v=0,ll w=0):v(v),w(w){}
};
vector<node> edge[220];
ll m,n,sum[220],dp[220][220];
void dfs(ll x,ll father)
{
	for(ll i=0;i<edge[x].size();i++)
	{
		ll y=edge[x][i].v;
		ll w=edge[x][i].w;
		if(y==father) continue;
		dfs(y,x);
		sum[x]=sum[x]+sum[y]+1;
		for(ll j=min(n,sum[x]);j>=0;j--)
		{
			for(ll k=0;k<=min(sum[y],j-1);k++) dp[x][j]=max(dp[x][j],dp[x][j-k-1]+dp[y][k]+w);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	for(ll i=1;i<=m;i++)
	{
		ll v,w;
		cin>>v>>w;
		edge[i].push_back(node(v,w));
		edge[v].push_back(node(i,w));
	}
	dfs(0,0);
	cout<<dp[0][n];
	return 0;
}
