#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll a[N];
struct Tree{
	ll lmax,rmax,maxx,sum;
};
Tree operator+(const Tree &a,const Tree &b){
	Tree res;
	res.sum=a.sum+b.sum;
	res.maxx=max(a.rmax+b.lmax,max(a.maxx,b.maxx));
	res.lmax=max(a.sum+b.lmax,a.lmax);
	res.rmax=max(b.rmax,b.sum+a.rmax);
	return res;
}
Tree tree[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p]=tree[ls(p)]+tree[rs(p)];
}
void update(ll x,ll c,ll p,ll pl,ll pr)
{
	if(pl==pr&&pl==x)
	{
		tree[p].sum=tree[p].maxx=tree[p].rmax=tree[p].lmax=c;
		return;
	}
	ll mid=(pl+pr)>>1;
	if(x<=mid) update(x,c,ls(p),pl,mid);
	else update(x,c,rs(p),mid+1,pr);
	push_up(p);
}
void build(ll p,ll pl,ll pr)
{
	tree[p].sum=tree[p].maxx=tree[p].rmax=tree[p].lmax=0;
	if(pl==pr)
	{
		tree[p].sum=tree[p].maxx=tree[p].rmax=tree[p].lmax=a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
Tree query(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr) return tree[p];
	ll mid=(pl+pr)>>1;
	if(r<=mid) return query(l,r,ls(p),pl,mid);
	if(l>mid) return query(l,r,rs(p),mid+1,pr);
	return query(l,r,ls(p),pl,mid)+query(l,r,rs(p),mid+1,pr);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,l,r,k;
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	cin>>m;
	while(m--)
	{
		cin>>k>>l>>r;
		if(k==1)  
		{
			if(l>r) swap(l,r);
			cout<<query(l,r,1,1,n).maxx<<"\n";	
		}		
        else update(l,r,1,1,n);
	}
	return 0;
}
