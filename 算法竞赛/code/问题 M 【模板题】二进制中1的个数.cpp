#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lowbit(ll x)
{
	return x&-x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,x;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		ll ans=0;
		while(x)
		{
			x=x-lowbit(x);
			ans++;
		}
		cout<<ans<<" ";
	}
	return 0;
}
