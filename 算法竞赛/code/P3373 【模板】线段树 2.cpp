#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct Tag{
	ll add,multi;
};
Tag tag[N<<2];
ll a[N],tree[N<<2],mod,n,q;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;};
void push_up(ll p)
{
	tree[p]=(tree[ls(p)]+tree[rs(p)])%mod;
}
void build(ll p,ll pl,ll pr)
{
	tag[p].add=0;
	tag[p].multi=1;
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
	ll mid=(pl+pr)>>1;
	tree[ls(p)]=(tree[ls(p)]*tag[p].multi%mod+tag[p].add*(mid-pl+1)%mod)%mod;
	tag[ls(p)].multi=(tag[ls(p)].multi*tag[p].multi)%mod;
	tag[ls(p)].add=(tag[ls(p)].add*tag[p].multi%mod+tag[p].add)%mod;
	tree[rs(p)]=(tree[rs(p)]*tag[p].multi%mod+tag[p].add*(pr-mid)%mod)%mod;
	tag[rs(p)].multi=(tag[rs(p)].multi*tag[p].multi)%mod;
	tag[rs(p)].add=(tag[rs(p)].add*tag[p].multi%mod+tag[p].add)%mod;
	tag[p].add=0;
	tag[p].multi=1;
}
void update_add(ll l,ll r,ll p,ll pl,ll pr,ll d)
{
	if(l<=pl&&r>=pr)
	{
		tag[p].add=(tag[p].add+d)%mod;
		tree[p]=(tree[p]+(pr-pl+1)*d%mod)%mod;
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(l<=mid) update_add(l,r,ls(p),pl,mid,d);
	if(r>mid) update_add(l,r,rs(p),mid+1,pr,d);
	push_up(p);
}
void update_multi(ll l,ll r,ll p,ll pl,ll pr,ll d)
{
	if(l<=pl&&r>=pr)
	{
		tag[p].multi=(tag[p].multi*d)%mod;
		tag[p].add=(tag[p].add*d)%mod;
		tree[p]=(tree[p]*d%mod)%mod;
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(l<=mid) update_multi(l,r,ls(p),pl,mid,d);
	if(r>mid) update_multi(l,r,rs(p),mid+1,pr,d);
	push_up(p);
}
ll query(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr) return tree[p];
	push_down(p,pl,pr);
	ll ans=0;
	ll mid=(pl+pr)>>1;
	if(l<=mid) ans=(ans+query(l,r,ls(p),pl,mid))%mod;
	if(r>mid) ans=(ans+query(l,r,rs(p),mid+1,pr))%mod;
	return ans%mod;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q>>mod;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		a[i]=a[i]%mod;
	}
	build(1,1,n);
	while(q--)
	{
		ll opt,l,r,k;
		cin>>opt;
		if(opt==1) 
		{
			cin>>l>>r>>k;
			update_multi(l,r,1,1,n,k);
		}
		else if(opt==2)
		{
			cin>>l>>r>>k;
			update_add(l,r,1,1,n,k);
		}
		else if(opt==3)
		{
			cin>>l>>r;
			cout<<query(l,r,1,1,n)<<"\n";
		}
	}
	return 0;
}
