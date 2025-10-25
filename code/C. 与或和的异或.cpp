#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll a[N],tree1[N<<2],tree2[N<<2],n,m;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree1[p]=tree1[ls(p)]&tree1[rs(p)];
	tree2[p]=tree2[ls(p)]|tree2[rs(p)];
} 
void build_tree(ll p,ll pl,ll pr)
{
	if(pl==pr) 
	{
		tree1[p]=tree2[p]=a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	build_tree(ls(p),pl,mid);
	build_tree(rs(p),mid+1,pr);
	push_up(p);
}
ll query1(ll l,ll r,ll p,ll pl,ll pr)
{
	if(pl>=l&&r>=pr) return tree1[p];
	ll mid=(pl+pr)>>1;
	ll ans=(1<<31)-1;
	if(l<=mid) ans=ans&query1(l,r,ls(p),pl,mid);
	if(r>mid) ans=ans&query1(l,r,rs(p),mid+1,pr);
	return ans;
}
ll query2(ll l,ll r,ll p,ll pl,ll pr)
{
	if(pl>=l&&r>=pr) return tree2[p];
	ll mid=(pl+pr)>>1;
	ll ans=0;
	if(l<=mid) ans=ans|query2(l,r,ls(p),pl,mid);
	if(r>mid) ans=ans|query2(l,r,rs(p),mid+1,pr);
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	build_tree(1,1,n);
	while(m--)
	{
		ll l,r;
		cin>>l>>r;
		ll ans1,ans2;
		ans1=query1(l,r,1,1,n);
		ans2=query2(l,r,1,1,n);
		cout<<(ans1^ans2)<<"\n";
	}
	return 0;
}
