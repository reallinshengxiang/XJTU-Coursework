#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&-(x))
const ll N=32010;
ll tree[N],b[N],n;
void update(ll x,ll d)
{
	while(x<=N)
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
		ll x,y;
		cin>>x>>y;
		x++;
		b[sum(x)]++;
		update(x,1);
	}
	for(ll i=0;i<=n-1;i++) cout<<b[i]<<"\n";
	return 0;
}
