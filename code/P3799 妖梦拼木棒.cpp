#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7,N=5e3+10;
ll p,num[N],ans;
ll fast_pow(ll x,ll n,ll mod)
{
	ll ans=1;
	x=x%mod;
	while(n)
	{
		if(n&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		n>>=1;
	}
	return ans;
}
ll cc(ll n,ll m,ll mod)
{
	if(m>n) return 0;
	if(m==0||m==n) return 1;
	if(m>n-m) m=n-m;
	ll up=1,down=1;
	for(ll i=1;i<=m;i++)
	{
		up=(up*(n-i+1))%mod;
		down=(down*i)%mod;
	}
	return up*fast_pow(down,mod-2,mod)%mod;
}
ll lucas(ll n,ll m,ll mod)
{
	if(m==0) return 1;
	return cc(n%mod,m%mod,mod)*lucas(n/mod,m/mod,mod)%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,maxx=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		num[x]++;
		maxx=max(maxx,x);
	}
	for(ll i=1;i<=maxx;i++)
	{
		if(num[i]>=2)
		{
			p=lucas(num[i],2,mod);
			for(ll j=1;j<=i/2;j++)
			{
				if(j!=i-j&&num[j]>=1&&num[i-j]>=1) ans=(ans+p*num[j]*num[i-j]%mod)%mod;
				else if(j==i-j&&num[j]>=2) ans=(ans+p*lucas(num[j],2,mod)%mod)%mod;
			}
		}
	}
	cout<<ans%mod;
	return 0;
}
