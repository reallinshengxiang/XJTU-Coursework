#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =2e5 + 10;
ll a[N],T,n,m,ans;
string s;
ll tree1[N<<2],tree[N<<2],tag[N<<2];
ll ls(ll p)
{
	return p<<1;
}
ll rs(ll p)
{
	return p<<1|1;
}
void push_up(ll p)
{                  
    tree[p] = tree[ls(p)] + tree[rs(p)]; 
}
void addtag(ll p,ll pl,ll pr)
{
	tag[p]=1;
	tree[p]=pr-pl+1;
}
void push_down(ll p,ll pl,ll pr)
{
	if(tag[p])
	{
		ll mid = (pl+pr)>>1;
		addtag(ls(p),pl,mid);
		addtag(rs(p),mid+1,pr);
		tag[p]=0;
	}
}
void update(ll L,ll R,ll p,ll pl,ll pr)
{
	if(L<=pl && pr<=R)
	{
		addtag(p,pl,pr);
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(L<=mid) update(L,R,ls(p),pl,mid);
	if(R>mid)  update(L,R,rs(p),mid+1,pr);
	push_up(p);
}
ll query(ll L,ll R,ll p,ll pl,ll pr)
{
	if(pl>=L && R >= pr) return tree[p];
	push_down(p,pl,pr);
	ll res=0;
	ll mid = (pl+pr)>>1;
	if(L<=mid) res+=query(L,R,ls(p),pl,mid);
	if(R>mid)  res+=query(L,R,rs(p),mid+1,pr);
	return res;
}
void push_up1(ll p)
{
	tree1[p] = tree1[ls(p)] + tree1[rs(p)];
}
void build1(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree1[p]=a[pl];
		return;
	}
	ll mid = (pl+pr) >> 1;
	build1(ls(p),pl,mid);
	build1(rs(p),mid+1,pr);
	push_up1(p);
}
ll query1(ll L,ll R,ll p,ll pl,ll pr)
{
	if(pl>=L&&R>=pr) return tree1[p];
	ll res=0;
	ll mid=(pl+pr)>>1;
	if(L<=mid) res+=query1(L,R,ls(p),pl,mid);
	if(R>mid)  res+=query1(L,R,rs(p),mid+1,pr);
	return res;
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		cin>>s;
		for(ll i=1; i<=n; i++) a[i]=s[i-1]-'0';
		build1(1,1,n);
		memset(tree,0,sizeof(tree));
		ans=0;
		while(m--)
		{
			ll l,r,x,y;
			cin>>l>>r;
			if(query(l,r,1,1,n)==r-l+1) continue;
			update(l,r,1,1,n);
			x=query1(l,r,1,1,n);
			y=query1(r-x+1,r,1,1,n);
			cout<<x<<"  "<<y<<"\n";
			if(x!=y)
			{
				ans++;
				cout<<ans<<"\n";
			}
		}
		if(ans==0) ans=1;
		cout<<ans<<"\n";
	}
	return 0;
}
