#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10,inf=1e16+10;
ll tree[N<<2],tag1[N<<2],tag2[N<<2],a[N],n,q;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
void build(ll p,ll pl,ll pr)
{
	tag1[p]=inf;
	tag2[p]=0;
	if(pl==pr)
	{
		tree[p]=a[pl];
		tag1[p]=inf;
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void addtag(ll p,ll pl,ll pr,ll d,ll opt)
{
	if(opt==1)
	{
		tag1[p]=tree[p]=d;
		tag2[p]=0;
	}
	else
	{
		tag2[p]=tag2[p]+d;
	    tree[p]=tree[p]+d;
	}	
}
void push_down(ll p,ll pl,ll pr)
{
	if(tag1[p]!=inf)
	{
		tree[ls(p)]=tree[rs(p)]=tag1[p];
		tag1[ls(p)]=tag1[rs(p)]=tag1[p];
		tag2[ls(p)]=tag2[rs(p)]=0;
		tag1[p]=inf;
	}
	if(tag2[p])
	{
		tree[ls(p)]=tree[ls(p)]+tag2[p];
		tree[rs(p)]=tree[rs(p)]+tag2[p];
		tag2[ls(p)]=tag2[ls(p)]+tag2[p];
		tag2[rs(p)]=tag2[rs(p)]+tag2[p];		
	    tag2[p]=0;	
    }
}
void update(ll l,ll r,ll p,ll pl,ll pr,ll d,ll opt)
{
	if(l<=pl&&r>=pr)
	{
		addtag(p,pl,pr,d,opt);
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(l<=mid) update(l,r,ls(p),pl,mid,d,opt);
	if(r>mid) update(l,r,rs(p),mid+1,pr,d,opt);
	push_up(p);
}
ll query(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr) return tree[p];
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	ll ans=-inf;
	if(l<=mid) ans=max(ans,query(l,r,ls(p),pl,mid));
	if(r>mid) ans=max(ans,query(l,r,rs(p),mid+1,pr));
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(q--)
	{
		ll opt,l,r,x;
		cin>>opt;
		if(opt==1||opt==2)
		{
			cin>>l>>r>>x;
			update(l,r,1,1,n,x,opt);
		}
		else if(opt==3)
		{
			cin>>l>>r;
			cout<<query(l,r,1,1,n)<<"\n";
		}
	}
	return 0;
} 
