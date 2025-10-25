#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,n;
ll prime(ll x)
{
	if(x<2) return 0;
	for(ll i=2;i<=x/i;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>x;
		if(prime(x)) cout<<"Yes\n";
		else cout<<"No\n"; 
	}
	return 0;
}
