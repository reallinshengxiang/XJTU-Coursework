#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&-(x))
const ll N=1e5+10;
struct shu{
	ll num,pos;
};
shu a[N];
ll tree[N],maxx=1,n;
bool cmp(shu a,shu b)
{
	if(a.num!=b.num) return a.num<b.num;
	return a.pos<b.pos;
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
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++)
	{
		update(a[i].pos,1);
		maxx=max(maxx,i-sum(i));
	}
	cout<<maxx;
	return 0;
}
