#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll T;
ll fast_pow(ll x,ll n)
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		ll n;
		cin>>n;
		cout<<(fast_pow(2,n-1)+mod-1)%mod<<"\n";
	}
	return 0;
}
