#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt;
ll is_prime(ll x)
{
	if(x==1) return 0;
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
	for(ll i=1;i;i++)
	{
		if(is_prime(i)) 
		{
			cnt++;
			cout<<cnt<<"  "<<i<<"\n";
			if(cnt==2025) return 0;
		} 
	}
	return 0;
} 
/*
17609
*/ 
