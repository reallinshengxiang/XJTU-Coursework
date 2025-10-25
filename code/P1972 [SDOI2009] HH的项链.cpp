#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rll register long long
const ll N=1e6+10;
#define lowbit(x) ((x)&-(x))
struct node{
	ll l,r,id;
};
node q[N];
ll tree[N],a[N],vis[N],n,m,ans[N];
bool cmp(node a,node b)
{
	return a.r<b.r;
}
void update(ll x,ll d)
{
	while(x<N)
	{
		tree[x]=tree[x]+d;
		x=x+lowbit(x);
	}
}
ll sum(ll x)
{
	ll ans=0;
	while(x>0)
	{
		ans=ans+tree[x];
		x=x-lowbit(x);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(rll i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(rll i=1;i<=m;i++) cin>>q[i].l>>q[i].r,q[i].id=i;
	sort(q+1,q+m+1,cmp);
	ll pos=1;
	for(rll i=1;i<=m;i++)
	{
		for(rll j=pos;j<=q[i].r;j++)
		{
			if(vis[a[j]]) update(vis[a[j]],-1);
			update(j,1);
			vis[a[j]]=j;
		}
		pos=q[i].r+1;
		ans[q[i].id]=sum(q[i].r)-sum(q[i].l-1);
	}
	for(rll i=1;i<=m;i++) cout<<ans[i]<<"\n";
	return 0;
}
