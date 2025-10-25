#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=1e4+10;
ll minn=1e9,maxx=-1e9,cnt,root;
struct node{
	ll ls,rs,key,pri,size;
};
node t[N];
void newnode(ll x)
{
	cnt++;
	t[cnt].size=1;
	t[cnt].ls=t[cnt].rs=0;
	t[cnt].key=x;
	t[cnt].pri=rand();
}
void update(ll u)
{
	t[u].size=t[t[u].ls].size+t[t[u].rs].size+1;
}
void split(ll u,ll x,ll &l,ll &r)
{
	if(u==0) {l=r=0;return;}
	if(t[u].key<=x)
	{
		l=u;
		split(t[u].rs,x,t[u].rs,r);
	}
	else
	{
		r=u;
		split(t[u].ls,x,l,t[u].ls);
	}
	update(u);
}
ll merge(ll l,ll r)
{
	if(l==0||r==0) return l+r;
	if(t[l].pri>t[r].pri)
	{
		t[l].rs=merge(t[l].rs,r);
		update(l);
		return l;
	}
	else
	{
		t[r].ls=merge(l,t[r].ls);
		update(r);
		return r;
	}
}
void insert(ll x)
{
	ll l,r;
	split(root,x,l,r);
	newnode(x);
	ll aa=merge(l,cnt);
	root=merge(aa,r);
}
void rak(ll x)
{
	ll l,r;
	split(root,x-1,l,r);
	cout<<t[l].size+1<<"\n";
	root=merge(l,r);
}
ll kth(ll u,ll k)
{
	if(k==t[t[u].ls].size+1) return u;
	if(k<=t[t[u].ls].size) return kth(t[u].ls,k);
	if(k>t[t[u].ls].size) return kth(t[u].rs,k-t[t[u].ls].size-1);
}
void pre(ll x)
{
	ll l,r;
	if(x<=minn)
	{
		cout<<"-2147483647\n";
		return;
	}
	split(root,x-1,l,r);
	cout<<t[kth(l,t[l].size)].key<<"\n";
	root=merge(l,r); 
}
void suc(ll x)
{
	ll l,r;
	if(x>=maxx)
	{
		cout<<"2147483647\n";
		return;
	}
	split(root,x,l,r);
	cout<<t[kth(r,1)].key<<"\n";
	root=merge(l,r); 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	while(n--)
	{
		ll opt,x;
		cin>>opt>>x;
		if(opt==1) rak(x);
		else if(opt==2) cout<<t[kth(root,x)].key<<"\n";
		else if(opt==3) pre(x);
		else if(opt==4) suc(x);
		else if(opt==5) 
		{
			insert(x);
			minn=min(minn,x);
			maxx=max(maxx,x);
		}
	}
	return 0;
}
