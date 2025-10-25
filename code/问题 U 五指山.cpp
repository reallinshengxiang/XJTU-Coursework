#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		ll n,d,xx,yy,c,cc,x,y;
		cin>>n>>d>>xx>>yy;
		c=(yy-xx+n)%n;
		cc=extend_gcd(d,n,x,y);
		if(c%cc!=0) cout<<"Impossible\n";
		else cout<<((x*(c/cc))%(n/cc)+(n/cc))%(n/cc)<<"\n";
	}
	return 0;
}
