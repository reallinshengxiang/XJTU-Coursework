#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100010;
ll ans=-1,k,n,coin[20],sum[N],c[N],dp[N];
ll find(ll x)
{   
    ll l=1,r=n;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(sum[mid]<=x)  l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k>>n;
	for(ll i=1;i<=k;i++) cin>>coin[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>c[i];
		sum[i]=sum[i-1]+c[i];
	}
	for(ll i=0;i<=(1<<k)-1;i++)
	{
		for(ll j=1;j<=k;j++)
		{
			if((i&(1<<(j-1)))==0) 	continue;
			ll xx=dp[i-(1<<(j-1))];
			ll pos=find(sum[xx]+coin[j]);
			dp[i]=max(dp[i],pos);
		}
	}
	for(ll i=0;i<=(1<<k)-1;i++)
	{
		if(dp[i]==n) 
		{
			ll xx=0;
			for(ll j=1;j<=k;j++)
			{
				if(!(i&(1<<(j-1)))) xx=xx+coin[j];
			}
			ans=max(ans,xx);
		}
	}
	cout<<ans;
	return 0;
}
