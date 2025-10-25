#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&-(x))
const ll N=1000010;
ll tree[N],n,m;
void update(ll x,ll d)
{
	while(x<=N)
	{
		tree[x]=tree[x]^d;
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
	cin>>n>>m;
	while(m--)
	{
		ll t,l,r,k;
		cin>>t;
		if(t==1)
		{
			cin>>l>>r;
			update(l,1);
			update(r+1,1);
		}
		else if(t==2)
		{
			cin>>k;
			cout<<(sum(k)%2)<<"\n";
		}
	}
	return 0;
}
