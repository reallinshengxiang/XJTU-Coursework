#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll l,k;
string s,ss;
ll is_prime(ll x)
{
	if(x<=1) return 0;
	if(x==2) return 1;
	for(ll i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>l>>k>>s;
	for(ll i=0;i<=l-k;i++)
	{
		ss=s.substr(i,k);
		ll tmp=0;
		for(ll j=0;j<=k-1;j++) tmp=tmp*10+ss[j]-'0';
		if(is_prime(tmp)) 
		{
			cout<<ss;
			return 0;
		}
	}
	cout<<404;
	return 0;
 } 
