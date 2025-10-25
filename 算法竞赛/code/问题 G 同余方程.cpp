#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll extend_gcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0) 
	{
		x=1;
		y=0;
		return a;
	}
	ll d=extend_gcd(b,a%b,y,x);
	y=y-a/b*x;
	return d;
}
ll mod_inverse(ll a,ll m)
{
	ll x,y;
	extend_gcd(a,m,x,y);
	return (x%m+m)%m;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a,b;
	cin>>a>>b;
	cout<<mod_inverse(a,b);
	return 0;
}
