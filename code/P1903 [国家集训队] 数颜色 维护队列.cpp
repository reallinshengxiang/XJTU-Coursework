#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rll register long long
const ll N=1e6+10;
struct node{
	ll l,r,t,id;
};
node q[N];
ll anss[N],cnt1,cnt2,ans,n,m,pos[N],cnt[N],a[N],block;
char ch;
bool cmp(node a,node b)
{
	if(a.l/block!=b.l/block) return a.l/block<b.l/block;
	if(a.r/block!=b.r/block) return a.r/block<b.r/block;
	return a.t<b.t;
}
struct change{
	ll pos,col;
};
change c[N];
void add(ll x)
{
	cnt[a[x]]++;
	if(cnt[a[x]]==1) ans++;
}
void del(ll x)
{
	cnt[a[x]]--;
	if(cnt[a[x]]==0) ans--;
}
void update(ll now,ll i)
{
	if(c[now].pos>=q[i].l&&c[now].pos<=q[i].r)
	{
		cnt[a[c[now].pos]]--;
		if(cnt[a[c[now].pos]]==0) ans--;
		cnt[c[now].col]++;
		if(cnt[c[now].col]==1) ans++; 
	}
	swap(c[now].col,a[c[now].pos]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	block=pow(n,0.66666667);
	for(ll i=1;i<=n;i++) cin>>a[i];
	while(m--)
	{
		cin>>ch;
		if(ch=='Q')
		{
			cnt1++;
			cin>>q[cnt1].l>>q[cnt1].r;
			q[cnt1].t=cnt2;
			q[cnt1].id=cnt1;
		}
		else if(ch=='R')
		{
			cnt2++;
			cin>>c[cnt2].pos>>c[cnt2].col;
		}
	}
	sort(q+1,q+cnt1+1,cmp);
	ll l=1,r=0,now=0; 
    for(rll i=1;i<=cnt1;i++)
    {
        while(l<q[i].l) del(l++);
        while(l>q[i].l) add(--l);
        while(r<q[i].r) add(++r);
        while(r>q[i].r) del(r--);
        while(now<q[i].t) update(++now,i);
        while(now>q[i].t) update(now--,i);
        anss[q[i].id]=ans;
    }
    for(rll i=1;i<=cnt1;i++) cout<<anss[i]<<"\n";
	return 0;
}
