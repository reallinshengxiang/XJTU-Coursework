#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,ans,a[N],x,T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll k=1;k<=n;k++)
		{
			if(n%k) continue;
			x=0;
			for(ll i=k+1;i<=n;i++) x=__gcd(x,abs(a[i]-a[i-k]));
			if(x!=1) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
