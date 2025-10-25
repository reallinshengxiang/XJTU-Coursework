#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll a[N],m[N];
ll mul(ll a,ll b,ll mod)
{
	ll ans=0;
	while(b>0)
	{
		if(b&1) ans=(ans+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return ans;
}
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
ll excrt()
{
	ll x,y,m1=m[1],a1=a[1],ans=0;
	for(ll i=2;i<=3;i++)
	{
		ll m2=m[i],a2=a[i];
		ll a=m1,b=m2,c=(a2-a1%m2+m2)%m2;
		ll d=extend_gcd(a,b,x,y);
		if(c%d!=0) return -1;
		x=mul(x,c/d,b/d);
		ans=a1+x*m1;
		m1=m2/d*m1;
		ans=(ans%m1+m1)%m1;
		a1=ans;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll dd,cnt=0;
	while(cin>>a[1]>>a[2]>>a[3]>>dd)
	{
		if(a[1]==-1&&a[2]==-1&&a[3]==-1&&dd==-1) break;
		m[1]=23;
		m[2]=28;
		m[3]=33;
		cnt++;
		cout<<"Case "<<cnt<<": the next triple peak occurs in "<<((excrt()-dd+21251)%21252+1)<<" days.\n";
	}	
	return 0;
}
