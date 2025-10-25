#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct Tree{
	ll sum,max;
};
Tree tree[N<<2];
ll n,a[N],m;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p].sum=tree[ls(p)].sum+tree[rs(p)].sum;
	tree[p].max=max(tree[ls(p)].max,tree[rs(p)].max);
}
void build(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree[p].sum=tree[p].max=a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void update(ll l,ll r,ll p,ll pl,ll pr)
{
	if(tree[p].max<=1) return;
	if(pl==pr)
	{
		a[pl]=sqrt(a[pl]);
		tree[p].max=tree[p].sum=a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	if(l<=mid) update(l,r,ls(p),pl,mid);
	if(r>mid) update(l,r,rs(p),mid+1,pr);
	push_up(p);
}
ll query(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr) return tree[p].sum;
	ll mid=(pl+pr)>>1,ans=0;
	if(l<=mid) ans=ans+query(l,r,ls(p),pl,mid);
	if(r>mid) ans=ans+query(l,r,rs(p),mid+1,pr);
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	cin>>m;
	while(m--)
	{
		ll k,l,r;
		cin>>k>>l>>r;
		if(l>r)  swap(l,r);
		if(k==0) update(l,r,1,1,n);
		else cout<<query(l,r,1,1,n)<<"\n";
	}
	return 0;
}
