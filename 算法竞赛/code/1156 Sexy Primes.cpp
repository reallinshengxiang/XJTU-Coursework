#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
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
	cin>>n;
	if(is_prime(n)&&is_prime(n-6))	cout<<"Yes\n"<<n-6;
    else if(is_prime(n)&&is_prime(n+6))	cout<<"Yes\n"<<n+6;
    else
    {
    	for(ll i=n+1;i;i++)
    	{
    		if(is_prime(i)&&(is_prime(i-6)||is_prime(i+6)))
    		{
    			cout<<"No\n"<<i;
    			return 0;
			}
		}
	}
	return 0;
}
