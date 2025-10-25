#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1010;
ll ans,n,t[N],dp1[N],dp2[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>t[i];
	for(ll i=1;i<=n;i++)
	{
		dp1[i]=1;
		for(ll j=1;j<=i-1;j++) 
		{
			if(t[j]<t[i]) dp1[i]=max(dp1[i],dp1[j]+1);
		}
	}
	for(ll i=n;i>=1;i--)
	{
		dp2[i]=1;
		for(ll j=n;j>=i+1;j--)
		{
			if(t[j]<t[i]) dp2[i]=max(dp2[i],dp2[j]+1);
		}
	}
	for(ll i=1;i<=n;i++) ans=max(ans,dp1[i]+dp2[i]-1);
	cout<<n-ans;
	return 0;
}
