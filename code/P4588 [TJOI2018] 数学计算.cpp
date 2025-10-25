#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll tree[N<<2],mod,T,q,opt,m;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p]=(tree[ls(p)]*tree[rs(p)])%mod;
}
void build(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree[p]=1;
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void update(ll l,ll r,ll p,ll pl,ll pr,ll d)
{
	if(l<=pl&&pr<=r)
	{
		tree[p]=d%mod;
		return;
	}
	ll mid=(pl+pr)>>1;
	if(l<=mid) update(l,r,ls(p),pl,mid,d);
	if(r>mid) update(l,r,rs(p),mid+1,pr,d);
	push_up(p);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>q>>mod;
		build(1,1,q);
		for(ll i=1;i<=q;i++)
		{
			cin>>opt>>m;
			if(opt==1) update(i,i,1,1,q,m);
			else if(opt==2)	update(m,m,1,1,q,1);
            cout<<tree[1]%mod<<"\n";
		}
	} 
	return 0;
}
