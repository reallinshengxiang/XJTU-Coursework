#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
struct stone{
	ll w,v;
};
stone a[N];
struct qujian{
	ll l,r;
};
qujian b[N];
ll l,r,n,m,s,mid,y,sum1[N],sum2[N],ans=0x7f7f7f7f7f7f7f;
ll check(ll mid)
{
	y=0;
	for(ll i=1;i<=n;i++)
	{
		if(a[i].w>=mid) sum1[i]=sum1[i-1]+1,sum2[i]=sum2[i-1]+a[i].v;
		else sum1[i]=sum1[i-1],sum2[i]=sum2[i-1];
	}
	for(ll i=1;i<=m;i++) y=y+(sum1[b[i].r]-sum1[b[i].l-1])*(sum2[b[i].r]-sum2[b[i].l-1]);
	return s-y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++) cin>>a[i].w>>a[i].v,r=max(r,a[i].w);
	for(ll i=1;i<=m;i++) cin>>b[i].l>>b[i].r;
	while(l<=r)
	{
		mid=(l+r)/2;
		ll xx=check(mid);
		ans=min(ans,abs(xx));
		if(xx>=0) r=mid-1;
		else l=mid+1;
		if(ans==0) break;
	}
	cout<<ans;
	return 0;
}
