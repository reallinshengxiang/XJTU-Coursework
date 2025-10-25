#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10,inf=2e8;
#define lowbit(x) ((x)&-(x))
struct point{
	ll x,y,idx,t;
};
point p[N];
bool cmp(point a,point b)
{
	if(a.t<b.t) return 1;
	if(a.t==b.t&&a.x<b.x) return 1;
	return 0;
}
ll tree[N],px[N],n,k,cnt;
void update(ll x,ll d)
{
	while(x<N)
	{
		tree[x]=tree[x]+d;
		x=x+lowbit(x);
	}
}
ll sum(ll x)
{
	ll ans=0;
	while(x>0)
	{
		ans=ans+tree[x];
		x=x-lowbit(x);
	}
	return ans;
}
ll check(ll kk)
{
	for(ll i=1;i<=n;i++) p[i].t=p[i].y-kk*p[i].x;
	sort(p+1,p+n+1,cmp);
	memset(tree,0,sizeof(tree));
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		update(p[i].idx,1);
		ans=ans+sum(p[i].idx-1);
	}
	if(ans>=k) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
		px[i]=p[i].x;
	}
	sort(px+1,px+n+1);
	cnt=unique(px+1,px+n+1)-(px+1);
	for(ll i=1;i<=n;i++) p[i].idx=lower_bound(px+1,px+cnt+1,p[i].x)-px;
	ll l=-inf,r=inf,ans;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) 
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
