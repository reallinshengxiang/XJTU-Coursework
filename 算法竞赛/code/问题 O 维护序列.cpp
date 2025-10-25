#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct Tree{
	ll sum,add,mul;
};
Tree tree[N<<2];
ll a[N],n,mod,m;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p].sum=(tree[ls(p)].sum+tree[rs(p)].sum)%mod;
}
void build(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree[p].sum=a[pl];
		tree[p].add=0;
		tree[p].mul=1;
		return;
	}
	tree[p].add=0;
	tree[p].mul=1;
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void addtag(ll p,ll pl,ll pr,ll add,ll mul)
{
	tree[p].sum=(tree[p].sum*mul+(pr-pl+1)*add)%mod;
	tree[p].mul=(tree[p].mul*mul)%mod;
	tree[p].add=(tree[p].add*mul+add)%mod;
}
void push_down(ll p,ll pl,ll pr)
{
	ll mid=(pl+pr)>>1;
	addtag(ls(p),pl,mid,tree[p].add,tree[p].mul);
	addtag(rs(p),mid+1,pr,tree[p].add,tree[p].mul);
	tree[p].add=0;
	tree[p].mul=1;
}
void update(ll l,ll r,ll p,ll pl,ll pr,ll add,ll mul)
{
	if(l<=pl&&r>=pr)
	{
		addtag(p,pl,pr,add,mul);
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(l<=mid) update(l,r,ls(p),pl,mid,add,mul);
	if(r>mid) update(l,r,rs(p),mid+1,pr,add,mul);
	push_up(p); 
}
ll query(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr) return tree[p].sum;
	push_down(p,pl,pr);
	ll ans=0;
	ll mid=(pl+pr)>>1;
	if(l<=mid) ans=(ans+query(l,r,ls(p),pl,mid))%mod;
	if(r>mid) ans=(ans+query(l,r,rs(p),mid+1,pr))%mod;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>mod;
	for(ll i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	cin>>m;
	while(m--)
	{
		ll k,t,g,c;
		cin>>k;
		if(k==1)
		{
			cin>>t>>g>>c;
			update(t,g,1,1,n,0,c);
		}
		else if(k==2)
		{
			cin>>t>>g>>c;
			update(t,g,1,1,n,c,1);
		}
		else 
		{
			cin>>t>>g;
			cout<<(query(t,g,1,1,n)%mod)<<"\n";
		}
	}
	return 0;
}
