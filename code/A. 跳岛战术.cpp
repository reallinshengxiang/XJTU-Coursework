#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2020],s[2020],dp[2020],n,v,t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>v>>t;
	for(ll i=2;i<=n;i++) cin>>a[i];
	s[1]=0; 
	for(ll i=2;i<=n;i++) s[i]=s[i-1]+a[i];
	dp[1]=0;
	for(ll i=2;i<=n;i++)
	{
       dp[i]=s[i]*v+t*(i-1);
	   for(ll j=1;j<=i-1;j++)
	   {
	   	  dp[i]=min(dp[i],dp[j]+(s[i]-s[j])*v+t+2*(s[i]-s[j+1]));
		  dp[i]=min(dp[i],dp[j]+(s[i]-s[j])*v+t*(i-j));	   	 
	   }
	}
	cout<<dp[n];
	return 0;
} 
