#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,s,a[100010];
ll check(ll x)
{
	ll cnt=1,ss=0;
	for(ll i=1;i<=n;i++)
	{
		if(ss+a[i]<=x) ss=ss+a[i];
		else
		{
			cnt++;
			if(cnt>m) return 1; 
			ss=a[i];
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	s=0;
	ll minn=0;
	for(ll i=1;i<=n;i++)  
	{
		cin>>a[i];
		minn=max(minn,a[i]);
		s=s+a[i];
	}
	ll l=minn,r=s;
	while(l<=r)
	{
		ll mid=(l+r)/2;  
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r+1;
	return 0;
}
