#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[100010],b[100010],nn;
ll dfs(ll l,ll r,ll x)
{
	ll s1=(l-1)/nn,s2=(r-1)/nn,ans=0;
	if(s1==s2)
	{
		for(ll i=l;i<=r;i++)
		{
			if(a[i]<=x) ans++;
		}
		return ans;
	}
	else 
	{
		for(ll i=l;i<=nn*(s1+1);i++)
		{
			if(a[i]<=x) ans++;
		}
		for(ll i=s1+1;i<=s2-1;i++)
		{
			ll xx=upper_bound(b+(s1+1)*nn+1,b+s1*nn+2*nn+1,x)-(b+s1*nn+nn);
			ans=ans+xx;
		}
		for(ll i=s2*nn+1;i<=r;i++)
		{
			if(a[i]<=x) ans++;
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	nn=sqrt(n);
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	ll k=n/nn;
	for(ll i=1;i<=k;i++) sort(b+(i-1)*nn+1,b+i*nn+1);
	if(n-k*nn!=0) sort(b+k*nn+1,b+n+1);
	for(ll i=1;i<=m;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		cout<<dfs(x,y,z)<<"\n";
	}
	return 0;
}
