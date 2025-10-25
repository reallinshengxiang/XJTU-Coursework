#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll a[N],tree[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p]=tree[ls(p)]+tree[rs(p)];
}
void build(ll p,ll pl,ll pr)
{
	if(pl==pr) 
	{
		tree[p]=a[pl];
		return ;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void update(ll x,ll c,ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree[p]=tree[p]+c;
		return;
	}
	ll mid=(pl+pr)>>1;
	if(x<=mid) update(x,c,ls(p),pl,mid);
	else update(x,c,rs(p),mid+1,pr);
	push_up(p);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,l,c,r;
	cin>>n;
	for(ll i=1;i<=n;i++)  cin>>a[i];
	build(1,1,n);
	cin>>l>>c;
	update(l,c,1,1,n);
	cin>>l>>r;
	for(ll i=l;i<=r;i++) cout<<tree[i]<<" ";
	return 0;
}
