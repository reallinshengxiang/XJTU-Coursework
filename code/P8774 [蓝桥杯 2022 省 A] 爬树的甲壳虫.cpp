#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353,N=1e5+10;
struct fs{
	ll x,y;
};
fs a[N];
ll p1,p2,s1=1,s2,s3,n;
ll fast_pow(ll a,ll n)
{
	ll ans=1;
	while(n)
	{
		if(n&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	for(ll i=1;i<=n;i++)
	{
		p1=a[i].x*fast_pow(a[i].y,mod-2)%mod;
		p2=(a[i].y-a[i].x)*fast_pow(a[i].y,mod-2)%mod;
		s3=(s3+s1)%mod;
		s2=(s2+s1*p1)%mod;
		s1=(s1*p2)%mod;
	}
	cout<<s3*fast_pow(mod+1-s2,mod-2)%mod;
	return 0;
}
