#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#pragma GCC optimize(2)
const ll N=15100;
ll cp[10]={0,1,2,10,20,40,100,200};
ll T,a[10],dp[N],sum,n,v[N],c[N],vis[N];
ld cc;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		map<ll,ll> mp,vis;
		mp[0]=1;
		sum=0;
		memset(dp,0,sizeof(dp));
		for(ll i=1;i<=7;i++) 
		{		
		    cin>>a[i],sum=sum+a[i]*cp[i];
			for(ll j=0;j<=a[i];j++)
			{
				for(ll k=sum;k>=0;k--)
				{
					if(mp[k]==1) mp[k+j*cp[i]]=1;
				}
			}
		}
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>cc>>v[i],c[i]=cc*2,vis[c[i]]=1;
		vis[0]=1;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=sum-c[i];j>=0;j--) 
			{
				if(vis[j]) dp[j+c[i]]=max(dp[j+c[i]],dp[j]+v[i]),vis[j+c[i]]=1;
			}
		}
		ll ans=-1;
		ll ff=0;
		for(ll i=sum;i>=1;i--)
		{
			if(mp[i]&&vis[i]) ans=max(ans,dp[i]),ff=1;
		}
		if(ans>0||ff) cout<<ans<<"\n";
		else cout<<"-1\n";		
	}
	return 0;
 } 
