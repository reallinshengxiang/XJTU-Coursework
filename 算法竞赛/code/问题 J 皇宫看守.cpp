#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1510;
struct Edge{
	ll next,to;
};
Edge edge[N];
ll head[N],w[N],ii,vis[N],k,cnt,n,dp[N][4],xx,ww,root;
void add_edge(ll x,ll y)
{
	cnt++;	
	edge[cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void dfs(ll x)
{
	ll dis=0x3f3f3f3f3f;
	for(ll i=head[x];i;i=edge[i].next)
	{
		ll y=edge[i].to;
		dfs(y);
		dp[x][0]=dp[x][0]+min(dp[y][1],dp[y][2]);
		dp[x][1]=dp[x][1]+min(dp[y][1],dp[y][2]);
		dis=min(dis,dp[y][2]-min(dp[y][2],dp[y][1]));
		dp[x][2]=dp[x][2]+min(dp[y][2],min(dp[y][1],dp[y][0]));
	}
	dp[x][1]=dp[x][1]+dis;
	dp[x][2]=dp[x][2]+w[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>ii>>ww>>k;
		w[ii]=ww;
		while(k--)  
		{
			cin>>xx;
			add_edge(ii,xx);
			vis[xx]=1;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			root=i;
			break;
		}
	}
	dfs(root);
	cout<<min(dp[root][1],dp[root][2]);
	return 0;
}
