#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
ll msize,n,m,x,pos;
unordered_map<ll,ll> h;
ll is_prime(ll x)
{
	if(x<=1) return 0;
	if(x==2) return 1;
	for(ll i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0; 
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>msize>>n>>m;
	for(ll i=max(msize,n);i;i++)
	{
		if(is_prime(i))
		{
			msize=i;
			break;
		}
	} 
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		ll flag=0;
		for(ll k=0;k<=msize-1;k++)
		{
			pos=(x+k*k)%msize;
			if(h[pos]==0||h[pos]==x) 
			{
				h[pos]=x,flag=1;
				break;
			}
		} 
		if(!flag) cout<<x<<" cannot be inserted.\n"; 
	}
	ll ave=0;
	for(ll i=1;i<=m;i++)
	{
		cin>>x;
		for(ll k=0;k<=msize;k++)
		{
			ave=ave+1;
			pos=(x+k*k)%msize;
			if(h[pos]==x||h[pos]==0) break;
		}
	}
	cout<<fixed<<setprecision(1)<<(ld)ave*1.0/m;
	return 0;
}
