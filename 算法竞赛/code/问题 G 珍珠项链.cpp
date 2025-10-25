#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll N=2e5+10,pp=131313;
ll n,a[N],p[N],h[N],b[N],c[N],t[N],cnt,maxx,minn;
map<ll,ll> mp;
bool cmp(ll x,ll y)
{
	return x>y;
}
ll get_hash1(ll l,ll r)
{
	return h[r]-h[l-1]*p[r-l+1];
}
ll get_hash2(ll l,ll r)
{
	return t[l]-t[r+1]*p[r-l+1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	p[0]=1;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++) p[i]=p[i-1]*pp;
	for(ll i=1;i<=n;i++) h[i]=h[i-1]*pp+a[i];
	for(ll i=n;i>=1;i--) t[i]=t[i+1]*pp+a[i];
	for(ll k=1;k<=n;k++)
	{
		mp.clear();
		if(n/k<maxx) break;
		for(ll i=1;i<=n/k;i++)
		{
			minn=min(get_hash1((i-1)*k+1,i*k),get_hash2((i-1)*k+1,i*k));
			if(!mp.count(minn))	mp[minn]=1;						
		}
		b[k]=mp.size();
		maxx=max(maxx,b[k]);
	}
	cout<<maxx<<" ";
	for(ll i=1;i<=n;i++)
	{
		if(b[i]==maxx)
		{
			cnt++;
			c[cnt]=i;
		}
	}
	cout<<cnt<<"\n";
	for(ll i=1;i<=cnt;i++) cout<<c[i]<<" ";
	return 0;
}
