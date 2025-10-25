#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&-(x))
const ll N=1000010;
ll tree[N],q,n;
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
	cin>>n>>q;
	for(ll i=1;i<=n;i++) 
	{
		ll x;
		cin>>x;
		update(i,x);
	}
	while(q--)
	{
		ll qq,i,x,l,r;
		cin>>qq;
		if(qq==1) 
		{
			cin>>i>>x;
			update(i,x);
			for(ll i=1;i<=n;i++) cout<<tree[i]<<" ";
			cout<<"\n";
		}
		else
		{
			cin>>l>>r;
			cout<<sum(r)-sum(l-1)<<"\n";
		}
	}
	return 0;
} 
