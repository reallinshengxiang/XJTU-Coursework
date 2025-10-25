#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
struct Tree{
	ll maxl,maxr,sum;
};
Tree tree[N<<2];
ll n,m,a[N];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p,ll pl,ll pr)
{
	ll mid=(pl+pr)>>1;
	tree[p].maxl=tree[ls(p)].maxl;
	tree[p].maxr=tree[rs(p)].maxr;
	tree[p].sum=max(tree[ls(p)].sum,tree[rs(p)].sum);
	if(a[mid]!=a[mid+1])
	{
		if(mid-pl+1==tree[ls(p)].maxl) tree[p].maxl=max(tree[p].maxl,mid-pl+1+tree[rs(p)].maxl);
		if(pr-mid==tree[rs(p)].maxr) tree[p].maxr=max(tree[p].maxr,pr-mid+tree[ls(p)].maxr);
		tree[p].sum=max(tree[p].sum,tree[ls(p)].maxr+tree[rs(p)].maxl);
	}
}
void build(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree[p].maxl=tree[p].maxr=tree[p].sum=1;
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p,pl,pr);
}
void update(ll pos,ll p,ll pl,ll pr)
{
	if(pl==pr) 
	{
		a[pl]=a[pl]^1;
		return;
	}
	ll mid=(pl+pr)>>1;
	if(pos<=mid) update(pos,ls(p),pl,mid);
	else update(pos,rs(p),mid+1,pr);
	push_up(p,pl,pr);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	build(1,1,n);
	while(m--)
	{
		ll x;
		cin>>x;
	    update(x,1,1,n);
	    cout<<tree[1].sum<<"\n";
	}
	return 0;
}
