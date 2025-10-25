#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
const ll N=1e3+10;
struct mm{
	ll p,s,zc,yh;
};
mm a[N];
ll sum[N],n,b;
bool cmp(mm x,mm y)
{
	if(x.zc<y.zc) return 1;
	return 0;
}
ll check(ll x)
{
	
	for(ll i=x;i<=n;i++) 
	{
		if(sum[x-1]+a[i].yh<=b) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>b;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].p>>a[i].s;
		a[i].zc=a[i].p+a[i].s;
		a[i].yh=(a[i].p/2)+a[i].s;
	}
	sort(a+1,a+n+1,cmp); 
	for(ll i=1;i<=n;i++)  sum[i]=sum[i-1]+a[i].zc;
    ll l=1,r=n,mid,ans=0;
    while(l<=r)
    {
    	ll mid=(l+r)/2;
    	if(check(mid)) l=mid+1,ans=mid;
    	else r=mid-1;
	}
	cout<<ans;
	return 0;
 } 
