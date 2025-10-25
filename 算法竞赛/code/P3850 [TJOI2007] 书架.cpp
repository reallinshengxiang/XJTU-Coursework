#include<bits/stdc++.h>
using namespace std;
#define ll int
#define rll register int
const ll N=2e5+10;
ll root,cnt;
struct Node{
	ll ls,rs,pri,size;
	string val;
};
Node t[N]; 
string a[N];     
void update(ll u)
{
	t[u].size=t[t[u].ls].size+t[t[u].rs].size+1;
}
ll newnode(string x)
{
	cnt++;
	t[cnt].size=1;
	t[cnt].pri=rand();
	t[cnt].ls=t[cnt].rs=0;
	t[cnt].val=x;
	return cnt;
}
void split(ll u,ll x,ll &l,ll &r)
{
	if(u==0)
	{
		l=r=0;
		return;
	}
	if(t[t[u].ls].size+1<=x)
	{
		l=u;
		split(t[u].rs,x-t[t[u].ls].size-1,t[u].rs,r);
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
};
void inorder(ll u)
{
	if(u==0) return;
	inorder(t[u].ls);
	cout<<t[u].val;
	inorder(t[u].rs);
}
ll build(ll l,ll r)
{
	if(l==r) return newnode(a[l]);
	ll mid=(l+r)>>1;
	return merge(build(l,mid),build(mid+1,r));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    srand(time(NULL));
    ll n,m,pos,l,p,r,q;
    string xx;
	cin>>n;
	for(rll i=1;i<=n;i++) cin>>a[i];
	root=build(1,n);
    cin>>m;
    for(rll i=1;i<=m;i++)
    {
    	cin>>xx>>pos;
    	split(root,pos,l,r);
    	l=merge(l,newnode(xx));
    	root=merge(l,r);
	}
	cin>>q;
	for(rll i=1;i<=q;i++)
	{
		cin>>pos;
		split(root,pos+1,l,r);
		split(l,pos,l,p);
		inorder(p);
		cout<<"\n";
		root=merge(merge(l,p),r);
	}
    return 0;
}
