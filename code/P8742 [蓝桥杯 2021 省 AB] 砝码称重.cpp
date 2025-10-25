#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll sum,dp[110][N],w[110],n,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>w[i],sum=sum+w[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=sum;j>=0;j--) 
		{
			if(j==w[i]) dp[i][j]=1;
			else if(dp[i-1][j]) dp[i][j]=1;
			else if(dp[i-1][j+w[i]]) dp[i][j]=1;
			else if(dp[i-1][abs(j-w[i])]) dp[i][j]=1;
		}
	}
	for(ll i=1;i<=sum;i++) ans=ans+dp[n][i];
	cout<<ans;
	return 0;
}
