#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct Tree{
	ll sum,tag;
};
Tree tree[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
ll pow2(ll x)
{
	ll ans=1;
	while(x)
	{
		ans=ans*2;
		x--;
	}
	return ans;
}
ll num_one(ll x)
{
	ll ans=0;
	while(x>0)
	{
		if(x%2) ans++;
		x>>=1;
	}
	return ans;
}
void push_up(ll p) 
{
	tree[p].sum=(tree[ls(p)].sum|tree[rs(p)].sum);
}
void build(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree[p].sum=(ll)1;
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void addtag(ll p,ll pl,ll pr,ll x)
{
	tree[p].sum=x;
	tree[p].tag=x;
}
void push_down(ll p,ll pl,ll pr)
{
	if(tree[p].tag!=0)
	{
		tree[ls(p)].tag=tree[rs(p)].tag=tree[ls(p)].sum=tree[rs(p)].sum=tree[p].tag;
		tree[p].tag=0;
	}
}
void update(ll l,ll r,ll p,ll pl,ll pr,ll x)
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
ll query(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr) return tree[p].sum;
	push_down(p,pl,pr); 
	ll ans=0,mid=(pl+pr)>>1;
	if(l<=mid) ans=(ans|query(l,r,ls(p),pl,mid));
	if(r>mid) ans=(ans|query(l,r,rs(p),mid+1,pr));
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll L,T,O;
	ll cnt=0;
	cin>>L>>T>>O;
	build(1,1,L);
	while(O--)
	{
		char opt;
		ll a,b,c;
		cin>>opt>>a>>b;
		if(a>b) swap(a,b);
		if(opt=='C')
		{
			cin>>c;
			update(a,b,1,1,L,pow2(c-1));
		}
		else cout<<num_one(query(a,b,1,1,L))<<"\n";
	}
	return 0;
}
