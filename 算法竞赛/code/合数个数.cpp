#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
ll prime(ll x)
{
	if(x==1||x==2||x==3||x==5) return 0;
	for(ll i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=2020;i++)
	{
		if(prime(i)) ans++;
	}
	cout<<ans;
	return 0;
}
