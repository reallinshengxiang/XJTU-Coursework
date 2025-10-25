#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,a[22],g[22][22],pre[22],dp[22],ed;
void print(ll x)
{
	if(pre[x]==0) 
	{
		cout<<x<<" ";
		return;
	}
	print(pre[x]);
	cout<<x<<" ";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			cin>>g[i][j];
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(g[j][i]&&dp[j]>dp[i])
			{
				dp[i]=dp[j];
				pre[i]=j;
			}
		}
		dp[i]=dp[i]+a[i];
		if(dp[i]>ans)
		{
			ans=dp[i];
			ed=i;
		}
	}
	print(ed);
	cout<<"\n"<<ans;
	return 0;
} 
