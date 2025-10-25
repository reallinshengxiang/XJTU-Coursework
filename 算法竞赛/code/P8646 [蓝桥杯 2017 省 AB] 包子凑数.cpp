#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,a[N],dp[N],x,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		x=__gcd(x,a[i]);
	}
	if(x>=2)
	{
		cout<<"INF";
		return 0;
	}
	dp[0]=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=a[i];j<=1e5;j++) dp[j]=max(dp[j],dp[j-a[i]]);
	}
	for(ll i=1;i<=1e5;i++) ans=ans+dp[i];
	cout<<1e5-ans;
	return 0;
}
