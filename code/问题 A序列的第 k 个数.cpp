#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=200907;
ll fast_pow(ll x,ll n)
{
     ll ans=1;
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
	ll t,a,b,c,k,ans;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>k;
		if(a+c==2*b)
		{
			ans=(a+((b-a)%mod)*((k-1)%mod))%mod;
			cout<<ans<<"\n";
		}
		else
		{
			ans=fast_pow(b/a,k-1);
			cout<<a*ans%mod<<"\n";
		}
	}
	return 0;
 } 
