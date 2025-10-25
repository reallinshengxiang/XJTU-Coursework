#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cnt=sqrt(n)*2-1;
	cout<<cnt<<"\n";
	for(ll i=1;i<=sqrt(n);i++) cout<<(n/i+1)<<" "<<1<<"\n";
	ll x=sqrt(n)+1;
	for(ll i=x;i<=n;i++)
	{
		ll y=n/i;
		cout<<(n/i+1)<<" "<<(n/y-i+1)<<"\n";
		i=n/y;
	} 
	return 0;
}
