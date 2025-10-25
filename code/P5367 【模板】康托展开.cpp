#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&-(x))
const ll N=1e6+10,mod=998244353;
ll tree[N],jc[N],n,kth;
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
	//freopen("P5367_3.in","r",stdin);
	cin>>n;
	jc[0]=1;
	for(ll i=1;i<=n;i++) jc[i]=(jc[i-1]*i)%mod,update(i,1);
	for(ll i=1;i<=n;i++)
	{
		ll x;
		cin>>x;		
	//	cout<<sum(x-1)<<"  "<<jc[n-i]<<"\n"; 
		kth=(kth+((sum(x-1))*jc[n-i])%mod)%mod;//¼ÆËãans
		update(x,-1);
	}
	cout<<(kth+1)%mod;
	return 0;
}
