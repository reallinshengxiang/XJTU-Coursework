#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=200010;
ll cnt=0,n,m;
ll a[N],b[N],root[N];
struct{
	ll l,r,sum;
}tree[N<<5];
ll update(ll pre,ll pl,ll pr,ll x)
{
	cnt++;
	ll rt=cnt;
	tree[rt].l=tree[pre].l;
	tree[rt].r=tree[pre].r;
	tree[rt].sum=tree[pre].sum+1;
	ll mid=(pl+pr)>>1;
	if(pl<pr)
	{
		if(x<=mid) tree[rt].l=update(tree[pre].l,pl,mid,x);
		else tree[rt].r=update(tree[pre].r,mid+1,pr,x);
	}
	return rt;
}
ll query(ll u,ll v,ll pl,ll pr,ll k)
{
	if(pl==pr) return pl;
	ll x=tree[tree[v].l].sum-tree[tree[u].l].sum;
	ll mid=(pl+pr)>>1;
	if(x>=k)  return query(tree[u].l,tree[v].l,pl,mid,k);
	else return query(tree[u].r,tree[v].r,mid+1,pr,k-x); 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	ll size=unique(b+1,b+n+1)-b-1;
	for(ll i=1;i<=n;i++)
	{
		ll x=lower_bound(b+1,b+1+size,a[i])-b;
		root[i]=update(root[i-1],1,size,x);
	}
	while(m--)
	{
		ll x,y,k;
		cin>>x>>y>>k;
		ll t=query(root[x-1],root[y],1,size,k);
		cout<<b[t]<<"\n";
	}
	return 0;
}
