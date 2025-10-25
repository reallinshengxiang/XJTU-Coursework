#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,x,a[360],num[5],dp[44][44][44][44];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=m;i++)
	{
		cin>>x;
		num[x]++;
	}
	dp[0][0][0][0]=a[1];
	for(ll i=0;i<=num[1];i++)
	{
		for(ll j=0;j<=num[2];j++)
		{
			for(ll k=0;k<=num[3];k++)
			{
				for(ll g=0;g<=num[4];g++)
				{
					x=1+i+2*j+3*k+4*g;
					if(i) dp[i][j][k][g]=max(dp[i][j][k][g],dp[i-1][j][k][g]+a[x]);
					if(j) dp[i][j][k][g]=max(dp[i][j][k][g],dp[i][j-1][k][g]+a[x]);
					if(k) dp[i][j][k][g]=max(dp[i][j][k][g],dp[i][j][k-1][g]+a[x]);
					if(g) dp[i][j][k][g]=max(dp[i][j][k][g],dp[i][j][k][g-1]+a[x]);
				}
			}
		}
	}
	cout<<dp[num[1]][num[2]][num[3]][num[4]];
	return 0;
}
