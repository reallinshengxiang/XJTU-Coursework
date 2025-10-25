#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
#define lowbit(x) ((x)&-(x))
ll tree1[N],tree2[N],n,q;
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
	cin>>n>>q;
	ll last=0,x;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		update1(i,x-last);
		update2(i,(i-1)*(x-last));
		last=x;
	}
	while(q--)
	{
		ll p,l,r;
		cin>>p;
		if(p==1)
		{
			cin>>l>>r>>x;
			update1(l,x);
			update1(r+1,-x);
			update2(l,x*(l-1));
			update2(r+1,-x*r);
		}
		else
		{
			cin>>l>>r;
			x=r*sum1(r)-(l-1)*sum1(l-1)-sum2(r)+sum2(l-1);
			cout<<x<<"\n";
		}
	}
	return 0;
}
