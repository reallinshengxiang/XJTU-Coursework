#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=210;
ll n,head[N],tail[N],dp[N][N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>head[i];
		head[i+n]=head[i];
	}
	for(ll i=1;i<=2*n-1;i++) tail[i]=head[i+1];
	for(ll len=2;len<=n;len++)
	{
		for(ll i=1;i<=2*n-len+1;i++)
		{
			ll j=i+len-1;
			for(ll k=i;k<=j-1;k++) dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+head[i]*tail[k]*tail[j]);
		}
	}
	for(ll i=1;i<=n;i++) ans=max(ans,dp[i][i+n-1]);
	cout<<ans;
	return 0;
}
