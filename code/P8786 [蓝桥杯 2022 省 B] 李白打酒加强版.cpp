#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1000000007,N=110;
ll dp[N][N][N],n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	dp[0][0][2]=1;
	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=m;j++)
		{
			if(i==0&&j==0) continue;
			for(ll k=0;k<=m;k++)
			{
				if(k%2==0&&i) dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k/2])%mod;
				if(k+1<=m&&j) dp[i][j][k]=(dp[i][j-1][k+1]+dp[i][j][k])%mod;
			}
		}
	}
	cout<<dp[n][m-1][1];
	return 0;
}
