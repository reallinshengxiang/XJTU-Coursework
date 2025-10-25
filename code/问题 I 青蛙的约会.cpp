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
	y=y-(a/b)*x;
	return d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,x,y,L;
	cin>>x>>y>>m>>n>>L;
	ll a=n-m,c=x-y;
	if(a<0)
	{
		a=-a;
		c=-c;
	}
	ll d=extend_gcd(a,L,x,y);
	if(c%d) cout<<"Impossible";
	else cout<<((x*(c/d))%(L/d)+(L/d))%(L/d);
	return 0;
}
