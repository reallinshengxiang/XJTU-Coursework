#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll a[N],tree[N<<2],maxx[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p]=tree[ls(p)]+tree[rs(p)];
	maxx[p]=max(maxx[ls(p)],maxx[rs(p)]);
}
void build(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree[p]=maxx[p]=a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void update(ll l,ll r,ll p,ll pl,ll pr)
{
	if(maxx[p]<=1) return;
	if(pl==pr)
	{
		tree[p]=sqrt(tree[p]);
		maxx[p]=tree[p];
		return;
	}
	ll mid=(pl+pr)>>1;
	if(l<=mid) update(l,r,ls(p),pl,mid);
	if(r>mid) update(l,r,rs(p),mid+1,pr);
	push_up(p);
}
ll query(ll l,ll r,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr)  return tree[p];
	ll mid=(pl+pr)>>1,ans=0;
	if(l<=mid) ans=ans+query(l,r,ls(p),pl,mid);
	if(r>mid) ans=ans+query(l,r,rs(p),mid+1,pr);
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,x,l,r;
	cin>>n;
	for(ll i=1;i<=n;i++)  cin>>a[i];
	build(1,1,n);
	cin>>m;
	while(m--)
	{
		cin>>x>>l>>r;
		if(l>r) swap(l,r);
		if(x==1)  cout<<query(l,r,1,1,n)<<"\n";
		else if(x==2)  update(l,r,1,1,n);
	}
	return 0;
}
