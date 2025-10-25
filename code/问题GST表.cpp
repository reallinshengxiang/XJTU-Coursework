#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll tree[N<<2],a[N];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
void build(ll p,ll pl,ll pr)
{
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
ll query(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr) return tree[p];
	ll mid=(pl+pr)>>1,ans=0;
	if(l<=mid) ans=max(ans,query(l,r,ls(p),pl,mid));
	if(r>mid) ans=max(ans,query(l,r,rs(p),mid+1,pr));
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(m--)
	{
		ll l,r;
		cin>>l>>r;
		cout<<query(l,r,1,1,n)<<"\n";
	}
	return 0;
}
