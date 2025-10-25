#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e6+7;
ll x=1,n,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) 
	{
		n=n-i;
		ans=(ans+(i*x))%mod;
		x=(x*2)%mod;
	}
	cout<<(ans+n*x)%mod;
	return 0;
}
