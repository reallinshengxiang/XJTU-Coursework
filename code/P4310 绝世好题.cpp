#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=33;
ll n,a,k,dp[N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a;
		k=1;
		for(ll j=0;j<=30;j++)
		{
			if(a&(1<<j)) k=max(dp[j]+1,k);
		}
		for(ll j=0;j<=30;j++)
		{
			if(a&(1<<j)) dp[j]=max(dp[j],k);
		    ans=max(ans,dp[j]);
		}
	}
	cout<<ans;
	return 0;
}
