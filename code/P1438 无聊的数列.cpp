#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll tree[N<<2],tag[N<<2],a[N],n,m,opt;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p]=tree[ls(p)]+tree[rs(p)];
}
void addtag(ll p,ll pl,ll pr,ll d)
{
	tag[p]=tag[p]+d;
	tree[p]=tree[p]+(pr-pl+1)*d;
}
void build(ll p,ll pl,ll pr)
{
	tag[p]=0;
	if(pl==pr) 
	{
		tree[p]=a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void push_down(ll p,ll pl,ll pr)
{
	if(tag[p])
	{
		ll mid=(pl+pr)>>1;
		addtag(ls(p),pl,mid,tag[p]);
		addtag(rs(p),mid+1,pr,tag[p]);
		tag[p]=0;
	}
}
void update(ll l,ll r,ll p,ll pl,ll pr,ll d)
{
	if(l<=pl&&r>=pr)
	{
		addtag(p,pl,pr,d);
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(l<=mid) update(l,r,ls(p),pl,mid,d);
	if(r>mid) update(l,r,rs(p),mid+1,pr,d);
	push_up(p);
}
ll query(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr) return tree[p];
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1,ans=0;
	if(l<=mid) ans=ans+query(l,r,ls(p),pl,mid);
	if(r>mid) ans=ans+query(l,r,rs(p),mid+1,pr);
	return ans; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=n;i>=1;i--) a[i]=a[i]-a[i-1];
	build(1,1,n);
	while(m--)
	{
		cin>>opt;
		if(opt==1)
		{
			ll l,r,k,d;
			cin>>l>>r>>k>>d;
			update(l,l,1,1,n,k);
			if(l+1<=r) update(l+1,r,1,1,n,d);
			if(r+1<=n) update(r+1,r+1,1,1,n,-(k+d*(r-l)));
		}
		else
		{
			ll p;
			cin>>p;
			cout<<query(1,p,1,1,n)<<"\n";
		}
	}
	return 0;
}
