#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
#define lowbit(x) ((x)&-(x))
struct cow{
	ll num,pos;
};
cow a[N];
ll tree[N],ans[N],n;
vector<ll> e[N];
bool cmp1(cow a,cow b)
{
	if(a.num<b.num) return 1;
	return 0;
}
bool cmp2(cow a,cow b)
{
	if(a.pos<b.pos) return 1;
	return 0;
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
void dfs(ll now)
{
	ans[now]=-(sum(n)-sum(a[now].num));
	for(ll i=0;i<e[now].size();i++) dfs(e[now][i]);
	ans[now]=ans[now]+sum(n)-sum(a[now].num);
	update(a[now].num,1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].num;
		a[i].pos=i;
	}
	sort(a+1,a+n+1,cmp1);
	for(ll i=1;i<=n;i++) a[i].num=i;
	sort(a+1,a+n+1,cmp2);
	for(ll i=2;i<=n;i++)
	{
		ll x;
		cin>>x;
		e[x].push_back(i);
	}
	dfs(1);
	for(ll i=1;i<=n;i++) cout<<ans[i]<<"\n";
	return 0;
}
