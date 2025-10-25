#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll dp[N][N],p[N],INF,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,0x3f,sizeof(dp));
	INF=dp[0][0];
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>p[i];
	for(ll i=1;i<=n;i++) dp[i][i]=dp[i][i+1]=0;
	for(ll len=2;len<=n;len++)
	{
		for(ll i=1;i+len-1<=n;i++)
		{
			ll j=i+len-1;
			for(ll k=i+1;k<=j-1;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+p[i]*p[j]*p[k]);
		}
	}
	cout<<dp[1][n];
	return 0;
}
