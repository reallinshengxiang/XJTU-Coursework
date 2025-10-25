#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
struct shu{
	ll x,y;
	double value;
};
shu b[N];
bool cmp(shu a,shu b)
{
	if(a.value<b.value) return 1;
	return 0;
}
double xx,minn=1e12+10;
ll n,a[N],pos,ansx,ansy,ansz,x,y,nn,z;
map<ll,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>nn;
	for(ll i=1;i<=nn;i++) 
	{
		cin>>x;
		if(!mp[x])
		{
			a[++n]=x;
			mp[x]=1;
		}
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++)
	{
		b[i].x=a[i]/__gcd(a[i],a[i-1]);
		b[i].y=a[i-1]/__gcd(a[i],a[i-1]);
		b[i].value=b[i].x/b[i].y;
	}
	sort(b+2,b+n+1,cmp);
	b[1].x=b[1].y=b[1].value=1;
	for(ll i=2;i<=n;i++)
	{
		xx=b[i].x*b[i-1].y/b[i].y/b[i-1].x;
		if(xx==1) continue;
		if(minn>xx)
		{
			minn=xx;
			pos=i;
		}
	}
	ansx=b[pos].x*b[pos-1].y;
	ansy=b[pos].y*b[pos-1].x;
	ansz=__gcd(ansx,ansy);
	cout<<ansx/ansz<<"/"<<ansy/ansz;
	return 0;
}
