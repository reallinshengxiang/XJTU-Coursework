#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct cfx{
	ll w,h;
};
cfx a[N];
ll n,k;
bool check(ll x)
{
	ll sum=0;
	for(ll i=1;i<=n;i++) sum=sum+(a[i].w/x)*(a[i].h/x);
	if(sum>=k) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i].w>>a[i].h;
	ll l=1,r=N,mid,ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
