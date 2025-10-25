#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=100003;
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
	ll m,n,ans1,ans2;
	cin>>m>>n;
	ans1=fast_pow(m,n);
	ans2=(m*fast_pow(m-1,n-1))%mod;
	cout<<(ans1-ans2+mod)%mod;
	return 0;
}
