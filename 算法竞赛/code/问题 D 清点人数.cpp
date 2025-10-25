#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&-(x))
const ll N=100010;
ll tree[N],n,k;
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
	cin>>n>>k;
	while(k--)
	{
		char ch;
		ll m,p;
		cin>>ch;
		if(ch=='A') 
		{
			cin>>m;
			cout<<sum(m)<<"\n";
		}
		else if(ch=='B')
		{
			cin>>m>>p;
			update(m,p);
		}
		else
		{
			cin>>m>>p;
			update(m,-p);
		}
	}
	return 0;
}
