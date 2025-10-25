#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll ans,x,pos,p[N],b[N],n;
unordered_map<ll,ll> mp;
ll search(ll x)
{
	if(ans==0) return 1;
	ll l=1,r=ans,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(x<b[mid]) r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) 
	{
		cin>>x;
		mp[x]=i;
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>p[i];
		p[i]=mp[p[i]];
	}
	for(ll i=1;i<=n;i++)
	{
		pos=search(p[i]);
		if(pos>ans) ans++;
		b[pos]=p[i];
	}
	cout<<ans;
	return 0;
}
