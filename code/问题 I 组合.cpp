#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
	ll t,n,m,p;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>p;
		cout<<lucas(n,m,p)<<"\n";
	}
	return 0;
}
