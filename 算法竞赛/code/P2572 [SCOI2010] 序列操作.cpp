#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct Tree{
	ll sum,maxl1,maxr1,max1,maxl2,maxr2,max2,tag1,tag2,tag3;
};
Tree tree[N<<2];
ll n,m,a[N];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p,ll pl,ll pr)
{
	tree[p].sum=tree[ls(p)].sum+tree[rs(p)].sum;
	tree[p].maxl1=tree[ls(p)].maxl1;
	tree[p].maxl2=tree[ls(p)].maxl2;
	tree[p].maxr1=tree[rs(p)].maxr1;
	tree[p].maxr2=tree[rs(p)].maxr2;
	ll mid=(pl+pr)>>1;
	if(mid-pl+1==tree[ls(p)].maxl1) tree[p].maxl1=max(tree[p].maxl1,mid-pl+1+tree[rs(p)].maxl1);
	if(mid-pl+1==tree[ls(p)].maxl2) tree[p].maxl2=max(tree[p].maxl2,mid-pl+1+tree[rs(p)].maxl2);
	if(pr-mid==tree[rs(p)].maxr1) tree[p].maxr1=max(tree[p].maxr1,pr-mid+tree[ls(p)].maxr1);
	if(pr-mid==tree[rs(p)].maxr2) tree[p].maxr2=max(tree[p].maxr2,pr-mid+tree[ls(p)].maxr2);
	tree[p].max1=max(max(tree[ls(p)].max1,tree[rs(p)].max1),tree[ls(p)].maxr1+tree[rs(p)].maxl1);
	tree[p].max2=max(max(tree[ls(p)].max2,tree[rs(p)].max2),tree[ls(p)].maxr2+tree[rs(p)].maxl2);
}
void build(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree[p].max1=tree[p].maxl1=tree[p].maxr1=tree[p].sum=a[pl];
		tree[p].max2=tree[p].maxl2=tree[p].maxr2=1-a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p,pl,pr);
}
void opt1(ll p,ll pl,ll pr)
{
	ll mid=(pl+pr)>>1;
	tree[p].tag1=1;
	tree[p].tag2=tree[p].tag3=0;
	tree[p].sum=tree[p].maxl1=tree[p].maxr1=tree[p].max1=0;
	tree[p].maxl2=tree[p].maxr2=tree[p].max2=pr-pl+1;
}
void opt2(ll p,ll pl,ll pr)
{
	ll mid=(pl+pr)>>1;
	tree[p].tag2=1;
	tree[p].tag1=tree[p].tag3=0;
	tree[p].sum=pr-pl+1;
	tree[p].maxl2=tree[p].maxr2=tree[p].max2=0;
	tree[p].maxl1=tree[p].maxr1=tree[p].max1=pr-pl+1;
}
void opt3(ll p,ll pl,ll pr)
{
	ll mid=(pl+pr)>>1;
	tree[p].tag3=1-tree[p].tag3;
	tree[p].sum=(pr-pl+1)-tree[p].sum;
	swap(tree[p].maxl1,tree[p].maxl2);
	swap(tree[p].maxr1,tree[p].maxr2);
	swap(tree[p].max1,tree[p].max2);
}
void addtag(ll p,ll pl,ll pr,ll opt)
{
	if(opt==1) tree[p].tag2=tree[p].tag3=0,opt1(p,pl,pr);
	else if(opt==2) tree[p].tag1=tree[p].tag3=0,opt2(p,pl,pr);
	else if(opt==3) opt3(p,pl,pr);
}
void push_down(ll p,ll pl,ll pr)
{
	ll mid=(pl+pr)>>1;
	if(tree[p].tag1)
	{
		opt1(ls(p),pl,mid);
		opt1(rs(p),mid+1,pr);
		tree[p].tag1=0;
	}
	if(tree[p].tag2)
	{
		opt2(ls(p),pl,mid);
		opt2(rs(p),mid+1,pr);
		tree[p].tag2=0;
	}
	if(tree[p].tag3)
	{
		opt3(ls(p),pl,mid);
		opt3(rs(p),mid+1,pr);
		tree[p].tag3=0;
	}
}
void update(ll l,ll r,ll p,ll pl,ll pr,ll opt)
{
	if(l<=pl&&r>=pr)
	{
		addtag(p,pl,pr,opt);
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(l<=mid) update(l,r,ls(p),pl,mid,opt);
	if(r>mid) update(l,r,rs(p),mid+1,pr,opt);
	push_up(p,pl,pr);
}
ll query3(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr) return tree[p].sum;
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1,ans=0;
	if(l<=mid) ans=ans+query3(l,r,ls(p),pl,mid);
	if(r>mid) ans=ans+query3(l,r,rs(p),mid+1,pr);
	return ans;
}
Tree query4(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr) return tree[p];
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(r<=mid) return query4(l,r,ls(p),pl,mid);
	else if(l>mid) return query4(l,r,rs(p),mid+1,pr);
	else
	{
		Tree t1=query4(l,r,ls(p),pl,mid),t2=query4(l,r,rs(p),mid+1,pr),t;
		t.max1=max(t1.max1,t2.max1);
		t.maxl1=t1.maxl1;
		t.maxr1=t2.maxr1;
		if(t1.maxl1==mid-pl+1) t.maxl1=max(t.maxl1,mid-pl+1+t2.maxl1);
		if(t2.maxr1==pr-mid) t.maxr1=max(t.maxr1,pr-mid+t1.maxr1);
		t.max1=max(t.max1,t1.maxr1+t2.maxl1);
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
		ll opt,l,r;
		cin>>opt>>l>>r;
		l++;
		r++;
		if(opt<=2)
		{
			opt++;
			update(l,r,1,1,n,opt);
		}
		else if(opt==3) cout<<query3(l,r,1,1,n)<<"\n";
		else if(opt==4) cout<<query4(l,r,1,1,n).max1<<"\n";
	}
	return 0; 
}
