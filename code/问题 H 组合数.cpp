#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll fastpow(ll a,ll n)
{
	ll ans=1;
	a=a%mod;
	while(n)
	{
		if(n&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
}
ll cc(ll n,ll r)
{
	if(r>n) return 0;
	if(n==r||r==0) return 1;
	if(r>n-r) r=n-r;
	ll up=1,down=1;
	for(ll i=1;i<=r;i++)
	{
		up=(up*(n-i+1))%mod;
		down=(down*i)%mod;
	}
	return up*fastpow(down,mod-2)%mod;
}
ll lucas(ll n,ll r)
{
	if(r==0) return 1;
	return cc(n%mod,r%mod)*lucas(n/mod,r/mod)%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	cout<<lucas(n,m);
	return 0;
}
