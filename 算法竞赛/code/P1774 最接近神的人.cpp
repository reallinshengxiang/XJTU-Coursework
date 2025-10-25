#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&-(x))
const ll N=5e5+10;
struct shu{
	ll num,pos;
};
shu a[N];
ll tree[N],n;
bool cmp1(shu a,shu b)
{
	if(a.num<b.num) return 1;
	if(a.num==b.num&&a.pos<b.pos) return 1;
	return 0;
}
bool cmp2(shu a,shu b)
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
	ll ans=0;
	for(ll i=n;i>=1;i--)
	{
		update(a[i].num,1);
		ans=ans+sum(a[i].num-1);
	}
	cout<<ans;
	return 0;
}
