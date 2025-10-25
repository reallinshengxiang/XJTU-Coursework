#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
struct Tree{
	ll l,r,sum;
}; 
Tree tree[N<<6];
ll root[N],cnt;
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
ll query(ll u,ll v,ll pl,ll pr,ll x)
{
	if(pl==pr) return pl;
	ll mid=(pl+pr)>>1;
	if(2*(tree[tree[v].l].sum-tree[tree[u].l].sum)>x) return query(tree[u].l,tree[v].l,pl,mid,x);
	if(2*(tree[tree[v].r].sum-tree[tree[u].r].sum)>x) return query(tree[u].r,tree[v].r,mid+1,pr,x);
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,x,l,r;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>x;
		root[i]=update(root[i-1],1,n,x);
	}
	while(m--)
	{
		cin>>l>>r;
		cout<<query(root[l-1],root[r],1,n,r-l+1)<<"\n";
	}
	return 0;
}

