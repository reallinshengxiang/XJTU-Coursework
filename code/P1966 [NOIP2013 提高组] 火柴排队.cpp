#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&-(x))
const ll N=1e5+10,mod=1e8-3;
struct hc{
	ll num,pos;
};
hc a[N],b[N];
ll tree[N],n,c[N];
bool cmp(hc a,hc b)
{
	if(a.num<b.num) return 1;
	return 0;
}
void update(ll x,ll d)
{
	while(x<N)
	{
		tree[x]=(tree[x]+d)%mod;
		x=x+lowbit(x);
	}
} 
ll sum(ll x)
{
	ll ans=0;
	while(x>0)
	{
		ans=(ans+tree[x])%mod;
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
	for(ll i=1;i<=n;i++)
	{
		cin>>b[i].num;
		b[i].pos=i;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(ll i=1;i<=n;i++) c[a[i].pos]=b[i].pos;
	ll ans=0;
	for(ll i=n;i>=1;i--)
	{
		update(c[i],1);
		ans=(ans+sum(c[i]-1))%mod;
    }
	cout<<ans%mod;
	return 0;
}
