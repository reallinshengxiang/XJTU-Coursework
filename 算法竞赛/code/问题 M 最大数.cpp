#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll tree[N<<2],len,a,t,m,p;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{
	tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
void update(ll p,ll pl,ll pr,ll x,ll d)
{
	if(pl==x&&pr==x)
	{
		tree[p]=d;
		return;
	}
	ll mid=(pl+pr)>>1;
	if(x<=mid) update(ls(p),pl,mid,x,d);
	else update(rs(p),mid+1,pr,x,d);
	push_up(p);
}
ll query(ll l,ll r,ll p,ll pl,ll pr)
{
	if(pl>=l&&pr<=r) return tree[p];
	ll mid=(pl+pr)>>1;
	if(l>pr||r<pl)	return -1;
	return max(query(l,r,ls(p),pl,mid),query(l,r,rs(p),mid+1,pr));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>p;
	a=0;
	ll T=m;
	while(T--)
	{
		char ch;
		cin>>ch;
		if(ch=='A')
		{
			cin>>t;
			len++;
			update(1,1,m,len,(t+a)%p);
		}
		else
		{
			cin>>t;
			a=query(len-t+1,len,1,1,m);
			cout<<a<<"\n";
		}
	}
	return 0;
}
