#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll z,mod,n,a,b;
ll fast_pow(ll a,ll b,ll mod)
{
	ll ans=1%mod;
	while(b)
	{
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>z;
	while(z--)
	{
		cin>>mod;
		cin>>n;
		ll ans=0;
		for(ll i=1;i<=n;i++) 
		{
			cin>>a>>b;
		    ans=(ans+fast_pow(a,b,mod))%mod;	
		}
		cout<<ans<<"\n";
	}
	return 0;
}
