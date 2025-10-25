#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,x[100010];
ll check(ll d)
{
	ll p=x[1],cnt=1;	
	for(ll i=2;i<=n;i++)
	{
		if(x[i]>=p+d) 
		{
			cnt++;
			p=x[i];
			if(cnt>=m) return 1;
		}
	}	
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>x[i];
	sort(x+1,x+n+1);
	ll l=1,r=x[n];
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
