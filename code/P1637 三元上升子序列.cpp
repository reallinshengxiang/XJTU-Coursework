#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&-(x))
const ll N=1e5+10;
ll tree1[N],tree2[N],a[N],b[N],n,pl[N],pr[N],cnt;
map<ll,ll> mp;
void update1(ll x,ll d)
{
	while(x<N)
	{
		tree1[x]=tree1[x]+d;
		x=x+lowbit(x);
	}
}
ll sum1(ll x)
{
	ll ans=0;
	while(x>0)
	{
		ans=ans+tree1[x];
		x=x-lowbit(x);
	}
	return ans;
}
void update2(ll x,ll d)
{
	while(x<N)
	{
		tree2[x]=tree2[x]+d;
		x=x+lowbit(x);
	}
}
ll sum2(ll x)
{
	ll ans=0;
	while(x>0)
	{
		ans=ans+tree2[x];
		x=x-lowbit(x);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	for(ll i=1;i<=n;i++)
	{
		if(!mp[b[i]])
		{
			cnt++;
			mp[b[i]]=cnt;
		}
	}
	for(ll i=1;i<=n;i++) a[i]=mp[a[i]];
	for(ll i=1;i<=n;i++)
	{
		pl[i]=sum1(a[i]-1);
		update1(a[i],1);
	}
	for(ll i=n;i>=1;i--)
	{
	    pr[i]=n-i-sum2(a[i]);
	    update2(a[i],1);
	} 
	ll ans=0;
	for(ll i=1;i<=n;i++) ans=ans+pl[i]*pr[i];
	cout<<ans;
	return 0;
}
