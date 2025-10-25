#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct fj{
	ll s,e,d;
};
fj a[200010];
ll n,T,xx;
ll sum(ll x)
{
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		if(a[i].s>x) continue;
		ans=ans+(min(a[i].e,x)-a[i].s)/a[i].d+1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i].s>>a[i].e>>a[i].d;
		ll l=1,r=(1<<31)-1; 
		while(l<=r)
		{
			ll mid=(l+r)/2;
			if(sum(mid)%2==0) l=mid+1;
			else r=mid-1;
		}
		xx=sum(r+1)-sum(r);
		if(xx&1)  cout<<r+1<<" "<<xx<<"\n";
		else cout<<"There's no weakness.\n";		
	} 
	return 0;
}
