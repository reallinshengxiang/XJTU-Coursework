#include<bits/stdc++.h>
using namespace std;
#define ll int
#define rll register int
const ll N=5e5+10;
struct Node{
	ll ls,rs,size,val,cov,pri,lazy_rev,lazy_cov,sum,pre_max,suc_max,all_max;
};
Node t[N];
ll stk[N],a[N],n,m,root,cnt;
char opt[10];
ll newnode(ll x)
{
	ll cnt1=stk[cnt--];
	t[cnt1].size=1;
	t[cnt1].ls=t[cnt1].rs=t[cnt1].cov=t[cnt1].lazy_cov=t[cnt1].lazy_rev=0;
	t[cnt1].pri=rand();
	t[cnt1].sum=t[cnt1].val=x;
	t[cnt1].pre_max=t[cnt1].suc_max=max(0,x);
	t[cnt1].all_max=x;
	return cnt1;
}
void update(ll u)
{
	if(u==0) return;
	t[u].size=t[t[u].ls].size+t[t[u].rs].size+1;
	t[u].sum=t[t[u].ls].sum+t[t[u].rs].sum+t[u].val;
	t[u].pre_max=max(max(t[t[u].ls].pre_max,t[t[u].ls].sum+t[u].val+t[t[u].rs].pre_max),0);
	t[u].suc_max=max(max(t[t[u].rs].suc_max,t[t[u].rs].sum+t[u].val+t[t[u].ls].suc_max),0);
	t[u].all_max=max(t[u].val,t[u].val+t[t[u].ls].suc_max+t[t[u].rs].pre_max);
	if(t[u].ls) t[u].all_max=max(t[u].all_max,t[t[u].ls].all_max);
	if(t[u].rs) t[u].all_max=max(t[u].all_max,t[t[u].rs].all_max);
	
}
void rev(ll u)
{
	if(u==0) return;
	swap(t[u].ls,t[u].rs);
	swap(t[u].pre_max,t[u].suc_max);
	t[u].lazy_rev^=1;
}
void cov(ll u,ll cov)
{
	if(u==0) return;
	t[u].val=t[u].cov=cov;
	t[u].sum=t[u].size*cov;
	t[u].pre_max=t[u].suc_max=max(0,t[u].sum);
	t[u].all_max=max(cov,t[u].sum);
	t[u].lazy_cov=1;
}
void pushdown(ll u)
{
	if(u==0) return;
	if(t[u].lazy_rev)
	{
		if(t[u].ls) rev(t[u].ls);
		if(t[u].rs) rev(t[u].rs);
		t[u].lazy_rev=0;
	}
	if(t[u].lazy_cov)
	{
		if(t[u].ls) cov(t[u].ls,t[u].cov);
		if(t[u].rs) cov(t[u].rs,t[u].cov);
		t[u].lazy_cov=0;
	}
}
void split(ll u,ll x,ll &l,ll &r)
{
	if(u==0) {l=r=0; return;}
	pushdown(u);
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
		pushdown(l);
		t[l].rs=merge(t[l].rs,r);
		update(l);
		return l;
	}
	else
	{
		pushdown(r);
		t[r].ls=merge(l,t[r].ls);
		update(r);
		return r;
	}
}
void del(ll u)
{
	if(u==0) return;
	cnt++;
	stk[cnt]=u;
	if(t[u].ls) del(t[u].ls);
	if(t[u].rs) del(t[u].rs);
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
	cin>>n>>m;
	for(rll i=1;i<N;i++) stk[++cnt]=i;
	for(rll i=1;i<=n;i++) cin>>a[i];
	root=build(1,n);
	while(m--)
	{
		cin>>opt;
		if(opt[0]=='I')
		{
			ll pos,tot,x,y;
			cin>>pos>>tot;
			split(root,pos,x,y);
			for(rll i=1;i<=tot;i++) cin>>a[i];
			x=merge(x,build(1,tot));
			root=merge(x,y);
		}
		if(opt[0]=='D')
		{
			ll pos,tot,x,y,z;
			cin>>pos>>tot;
			split(root,pos-1,x,y);
			split(y,tot,y,z);
			del(y);
			root=merge(x,z);
		}
		if(opt[2]=='K')
		{
			ll pos,tot,col,x,y,z;
			cin>>pos>>tot>>col;
			split(root,pos-1,x,y);
			split(y,tot,y,z);
			cov(y,col);
			root=merge(merge(x,y),z);
		}
		if(opt[0]=='R')
		{
			ll pos,tot,x,y,z;
			cin>>pos>>tot;
			split(root,pos-1,x,y);
			split(y,tot,y,z);
			rev(y);
			root=merge(merge(x,y),z);
		}
		if(opt[0]=='G')
		{
			ll pos,tot,x,y,z;
			cin>>pos>>tot;
			split(root,pos-1,x,y);
			split(y,tot,y,z);
			cout<<t[y].sum<<"\n";
			root=merge(merge(x,y),z);
		}
		if(opt[2]=='X') cout<<t[root].all_max<<"\n";
	}
	return 0;
}
