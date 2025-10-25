#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e4+10;
ll n,t,f[N],a[N];
ll check(ll x)
{
	f[0]=0;
	deque<ll> dq;
	dq.push_back(0);
	for(ll i=1;i<=n;i++)
	{
		if(!dq.empty()&&dq.front()+x+1<i) dq.pop_front();
		f[i]=f[dq.front()]+a[i];	
	    while(!dq.empty()&&f[i]<=f[dq.back()]) dq.pop_back();
	    dq.push_back(i);					
	}
	ll ans=0x7f7f7f7f7f;
	for(ll i=n-x;i<=n;i++) ans=min(ans,f[i]);
	if(ans<=t) return 1;
    return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>t;
	for(ll i=1;i<=n;i++)   cin>>a[i];
	ll l=1,r=n;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid)) r=mid-1;
	    else l=mid+1;
	}
	cout<<(r+1);
	return 0;
}
