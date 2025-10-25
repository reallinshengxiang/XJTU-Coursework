#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=330;
struct node{
	ll k,s;
};
vector<node> edge[N];
ll n,m,dp[N][N];
void dfs(ll x,ll father)
{
	for(ll i=0;i<edge[x].size();i++)
	{
		ll y=edge[x][i].k,s=edge[x][i].s;
		if(y==father) continue;
		dfs(y,x);
		for(ll j=m+1;j>=1;j--)
		{
			for(ll k=0;k<=j-1;k++) dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[y][k]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		ll k,s;
		cin>>k>>s;
		edge[k].push_back((node){i,s});
		dp[i][1]=s;
	}
	dfs(0,-1);
	cout<<dp[0][m+1]; 
	return 0;
} 
