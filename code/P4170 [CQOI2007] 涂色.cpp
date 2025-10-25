#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[55];
ll dp[55][55],n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	memset(dp,127,sizeof(dp));
	for(ll i=1;i<=n;i++) dp[i][i]=1;
	for(ll len=2;len<=n;len++)
	{
		for(ll i=1;i<=n-len+1;i++)
		{
			ll j=i+len-1;
			if(s[i]==s[j]) dp[i][j]=min(dp[i][j],min(dp[i+1][j],dp[i][j-1]));
			else
			{
				for(ll k=i;k<=j-1;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
			
		}
	}
	cout<<dp[1][n];
	return 0;
}
