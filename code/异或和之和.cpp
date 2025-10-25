#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll a[N],tree[N<<2],tag[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p]=tree[ls(p)]^tree[rs(p)];
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
	ll res=0;
	ll mid=(pl+pr)>>1;
	if(l<=mid) res=res^query(l,r,ls(p),pl,mid);
	if(r>mid) res=res^query(l,r,rs(p),mid+1,pr);
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,l,c,r,ans=0;
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;j++) 	ans=ans+query(i,j,1,1,n);
	}
	cout<<ans;
	return 0;
}
