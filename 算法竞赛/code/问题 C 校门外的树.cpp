#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100010;
#define lowbit(x) ((x)&-(x))
ll tree1[N],tree2[N],n,m;
void update1(ll x,ll d)
{
	while(x<=N)
	{
		tree1[x]=tree1[x]+d;
		x=x+lowbit(x);
	}
}
void update2(ll x,ll d)
{
	while(x<=N)
	{
		tree2[x]=tree2[x]+d;
		x=x+lowbit(x);
	}
}
ll sum1(ll x)
{
	ll ans=0;
	while(x>0) 
	{
		ans=ans+tree1[x];
		x=x-lowbit(x);
	}
	return ans;
}
ll sum2(ll x)
{
	ll ans=0;
	while(x>0) 
	{
		ans=ans+tree2[x];
		x=x-lowbit(x);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	while(m--)
	{
		ll k,l,r;
		cin>>k>>l>>r;
		if(k==1)
		{
			update1(l,1);
			update2(r,1);
		}
		else  cout<<sum1(r)-sum2(l-1)<<"\n";
    }
	return 0;
}
