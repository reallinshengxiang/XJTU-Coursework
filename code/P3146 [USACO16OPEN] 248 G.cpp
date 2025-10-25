#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,dp[250][250],n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) 
	{
		cin>>dp[i][i];
		ans=max(ans,dp[i][i]);
	}
	
	for(ll len=2;len<=n;len++)
	{
		for(ll i=1;i<=n-len+1;i++)
		{
			ll j=i+len-1;
			for(ll k=i;k<=j-1;k++) 
			{
				if(dp[i][k]&&dp[i][k]==dp[k+1][j])
				{
					dp[i][j]=max(dp[i][j],dp[i][k]+1);
					ans=max(ans,dp[i][j]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
