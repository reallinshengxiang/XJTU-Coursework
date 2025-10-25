#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=310;
struct Edge{
	ll to,next;
};
Edge edge[N];
ll head[N],cnt,n,m,dp[N][N];
void addedge(ll from,ll to)
{
	cnt++;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
ll dfs(ll x)
{
	ll num=1;
	for(ll i=head[x];i!=-1;i=edge[i].next)
	{
		ll to=edge[i].to;	
		ll t=dfs(to);
		num=num+t;
		for(ll j=num;j>=0;j--)
		{
			for(ll k=0;k<=min(j-1,t);k++) dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[to][k]);
		}
	}
	return num;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	for(ll i=1;i<=n;i++)
	{
		ll p;
		cin>>p>>dp[i][1];
		addedge(p,i);
	}
	dfs(0);
	cout<<dp[0][m+1];
	return 0;
}
