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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a,b,c,k;
	while(cin>>a>>b>>c>>k)
	{
		if(a==0&&b==0&&c==0&&k==0) break;
		k=(1ll<<k);
		ll x,y;
		ll d=extend_gcd(c,k,x,y);
		ll cc=b-a;
		if(cc%d!=0) cout<<"FOREVER\n";
		else cout<<(((x*(cc/d))%(k/d)+(k/d))%(k/d))<<"\n";
	}
	return 0;
}
