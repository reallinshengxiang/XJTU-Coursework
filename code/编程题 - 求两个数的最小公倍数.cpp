#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll a,b;
ll gcd(ll a,ll b)
{
	ll t,r;
	if(a<b) 
	{
		t=a;
		a=b;
		b=t;
	}
	while(a%b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	cout<<a*b/gcd(a,b);
	return 0;
}
