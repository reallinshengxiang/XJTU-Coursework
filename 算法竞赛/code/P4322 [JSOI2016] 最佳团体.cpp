#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rll register long long
const ll N=2505;
const double eps=1e-5,inf=0x3f3f3f3f3f3f3f;
vector<ll> edge[N];
ll sum[N],k,n,r;
double dp[N][N],val[N],s[N],p[N];
void dfs(ll u,ll father)
{
	sum[u]=1;
	dp[u][1]=val[u];
	for(rll i=0;i<edge[u].size();i++)
	{
		ll v=edge[u][i];
		if(v==father) continue;
		dfs(v,u);
		sum[u]=sum[u]+sum[v];
		for(rll j=min(k+1,sum[u]);j>=2;j--)
		{
			for(rll k=0;k<=min(sum[v],j-1);k++) dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
		}
	}
}
ll check(double mid)
{
	for(rll i=0;i<=n;i++) val[i]=p[i]-mid*s[i];
	for(rll i=0;i<=n;i++)
	{
		for(rll j=1;j<=k+1;j++) dp[i][j]=-inf;
	}
	dfs(0,-1);
	if(dp[0][k+1]>0) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k>>n;
	for(rll i=1;i<=n;i++)
	{
		cin>>s[i]>>p[i]>>r;
		edge[r].push_back(i);
	}
	double l=0,r=1000,mid;
	while(r-l>eps)
	{
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(3)<<mid;
	return 0;
}
