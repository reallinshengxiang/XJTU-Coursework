#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,m,a[N],b[N],c[N],pos,cnt;
ll search(ll x)
{
	ll l=1,r=m;
	if(m==0) return 1;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(b[mid]>=x) l=mid+1;
		else r=mid-1;
	}
	return l;
}
ll find(ll x)
{
	ll l=1,r=cnt;
	if(cnt==0) return 1;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(c[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x;
	while(cin>>x)
	{
		n++;
		a[n]=x;
	}
	for(ll i=1;i<=n;i++)
	{
	   pos=search(a[i]);
	   b[pos]=a[i];
	   if(pos==m+1) m++;
	}
	cout<<m<<"\n";
	for(ll i=1;i<=n;i++)
	{
		pos=find(a[i]);
		if(pos==cnt+1) cnt++;
		c[pos]=a[i];
	}
	cout<<cnt;
	return 0;
}
