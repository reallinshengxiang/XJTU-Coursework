#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=1e5+10;
struct Tree{
	ld sum,pfsum,tag;
};
Tree tree[N<<2];
ll n,m;
ld a[N];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p].sum=tree[ls(p)].sum+tree[rs(p)].sum;
	tree[p].pfsum=tree[ls(p)].pfsum+tree[rs(p)].pfsum;
}
void build(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree[p].sum=a[pl];
		tree[p].pfsum=a[pl]*a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void addtag(ll p,ll pl,ll pr,ld x)
{
	tree[p].tag=tree[p].tag+x;
	tree[p].pfsum=tree[p].pfsum+2*x*tree[p].sum+x*x*(pr-pl+1);
	tree[p].sum=tree[p].sum+x*(pr-pl+1);
}
void push_down(ll p,ll pl,ll pr)
{
	if(tree[p].tag!=0)
	{
		ll mid=(pl+pr)>>1;
		addtag(ls(p),pl,mid,tree[p].tag);
		addtag(rs(p),mid+1,pr,tree[p].tag);
		tree[p].tag=0;
	}
}
void update(ll l,ll r,ll p,ll pl,ll pr,ld x)
{
	if(l<=pl&&r>=pr)
	{
		addtag(p,pl,pr,x);
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(l<=mid) update(l,r,ls(p),pl,mid,x);
	if(r>mid) update(l,r,rs(p),mid+1,pr,x);
	push_up(p);
}
ld query(ll l,ll r,ll p,ll pl,ll pr,ll opt)
{
	if(opt==2)
	{
		if(pl>=l&&pr<=r) return tree[p].sum;
		push_down(p,pl,pr);
		ld ans=0;
		ll mid=(pl+pr)>>1;
		if(l<=mid) ans=ans+query(l,r,ls(p),pl,mid,opt);
		if(r>mid) ans=ans+query(l,r,rs(p),mid+1,pr,opt);
		return ans;
	}
	else if(opt==3)
	{
		if(pl>=l&&pr<=r) return tree[p].pfsum;
		push_down(p,pl,pr);
		ld ans=0;
		ll mid=(pl+pr)>>1;
		if(l<=mid) ans=ans+query(l,r,ls(p),pl,mid,opt);
		if(r>mid) ans=ans+query(l,r,rs(p),mid+1,pr,opt);
		return ans;
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
		ll opt,x,y;
		ld k;
		cin>>opt;
		if(opt==1)
		{
			cin>>x>>y>>k;
			update(x,y,1,1,n,k);
		}
		else
		{
			cin>>x>>y;
			if(opt==2) cout<<fixed<<setprecision(4)<<query(x,y,1,1,n,opt)/(y-x+1)<<"\n";
			else cout<<fixed<<setprecision(4)<<query(x,y,1,1,n,3)/(y-x+1)-query(x,y,1,1,n,2)*query(x,y,1,1,n,2)/(y-x+1)/(y-x+1)<<"\n";
		}
	}
	return 0;
} 
