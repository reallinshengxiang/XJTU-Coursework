#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e4+10;
ll a[N],tree[N<<2],m,n,year[N],maxx;
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
	ll mid=(pl+pr)>>1;
	ll ans=0;
	if(l<=mid) ans=max(ans,query(l,r,ls(p),pl,mid));
	if(r>mid) ans=max(ans,query(l,r,rs(p),mid+1,pr));
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll y,r;
		cin>>y>>r;
		a[i]=r; 
		year[i]=y;
	}
	build(1,1,n);
	cin>>m;
	while(m--)
	{
		ll y,x,l,r,flag1=0,flag2=0;
		maxx=0;
		cin>>y>>x;
		if(x<=y)
		{
			cout<<"false\n";
			continue;
		}
		ll pos1=lower_bound(year+1,year+n+1,y)-year;
		ll pos2=lower_bound(year+1,year+n+1,x)-year;
		if(year[pos1]==y) flag1=1;
		if(year[pos2]==x) flag2=1;
		if(flag1==0) pos1--;
		if(pos1+1<=pos2-1) maxx=query(pos1+1,pos2-1,1,1,n);
		if(maxx>=a[pos2]&&flag2) cout<<"false\n";
		else if(flag1&&flag2&&a[pos1]<a[pos2]) cout<<"false\n";
		else if(maxx>=a[pos1]&flag1) cout<<"false\n";
		else if(flag1==0||flag2==0) cout<<"maybe\n";
		else if(pos2-pos1!=year[pos2]-year[pos1]) cout<<"maybe\n";
		else cout<<"true\n";
    }
	return 0;
}
