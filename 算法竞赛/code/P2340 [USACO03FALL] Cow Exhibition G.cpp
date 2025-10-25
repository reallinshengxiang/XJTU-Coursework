#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=440,M=800080;
struct cow{
	ll zs,qs;
};
cow c[N];
ll n,dp[M],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>c[i].zs>>c[i].qs;
	memset(dp,-0x3f,sizeof(dp));
	dp[400000]=0;
	for(ll i=1;i<=n;i++)
	{
		if(c[i].zs>=0)
		{
			for(ll j=800000;j>=c[i].zs;j--) dp[j]=max(dp[j],dp[j-c[i].zs]+c[i].qs);
		}
		else
		{
			for(ll j=0;j<=800000+c[i].zs;j++) dp[j]=max(dp[j],dp[j-c[i].zs]+c[i].qs); 
		}
	}
	for(ll i=400000;i<=800000;i++)
	{
		if(dp[i]>0) ans=max(ans,i+dp[i]-400000);
	}
	cout<<ans;
	return 0;
}
