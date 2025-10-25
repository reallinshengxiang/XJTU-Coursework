#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
struct Tree{
	ll maxl,maxr,max,sum;
};
Tree tree[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
ll n,m,a[N];
void push_up(ll p)
{
	tree[p].sum=tree[ls(p)].sum+tree[rs(p)].sum;
	tree[p].maxl=max(tree[ls(p)].sum+tree[rs(p)].maxl,tree[ls(p)].maxl);
	tree[p].maxr=max(tree[rs(p)].sum+tree[ls(p)].maxr,tree[rs(p)].maxr);
	tree[p].max=max(max(tree[ls(p)].max,tree[rs(p)].max),tree[ls(p)].maxr+tree[rs(p)].maxl);
}
void build(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree[p].maxl=tree[p].maxr=tree[p].max=tree[p].sum=a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void update(ll pos,ll p,ll pl,ll pr,ll x)
{
	if(pl==pr)
	{
		tree[p].maxl=tree[p].maxr=tree[p].max=tree[p].sum=x;
		return;
	}
	ll mid=(pl+pr)>>1;
	if(pos<=mid) update(pos,ls(p),pl,mid,x);
	else update(pos,rs(p),mid+1,pr,x);
	push_up(p);
}
Tree query(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr) return tree[p];
	ll mid=(pl+pr)>>1;
	if(r<=mid) return query(l,r,ls(p),pl,mid);
	else if(l>mid) return query(l,r,rs(p),mid+1,pr);
	else
	{
		Tree t1=query(l,r,ls(p),pl,mid);
		Tree t2=query(l,r,rs(p),mid+1,pr);
		Tree t;
		t.maxl=max(t1.maxl,t1.sum+t2.maxl);
		t.maxr=max(t2.maxr,t2.sum+t1.maxr);
		t.max=max(max(t1.max,t2.max),t1.maxr+t2.maxl);
		return t;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(m--)
	{
		ll opt,a,b;
		cin>>opt>>a>>b;
		if(opt==1)
		{
			if(a>b) swap(a,b);
			cout<<query(a,b,1,1,n).max<<"\n";
		}
		else update(a,1,1,n,b);
	} 
	return 0;
}
