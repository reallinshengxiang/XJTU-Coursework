#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e8+10;
ll ans,n,x,t[N][2],cnt=1;
void insert(ll xx)
{
	ll p=1;
	for(ll i=31;i>=0;i--)
	{
		ll y=((xx>>i)&1);
		if(!t[p][y])
		{
			cnt++;
			t[p][y]=cnt;
		}
		p=t[p][y];
	}
}
void search(ll xx,ll sum)
{
	ll p=1;
	for(ll i=31;i>=0;i--)
	{
		ll y=((xx>>i)&1);
		ll z=y^((x>>i)&1)^1;
		if(t[p][z])
		{
			p=t[p][z];
			sum=sum+(1<<i);
		}
		else p=t[p][z^1];
	}
	ans=max(sum,ans);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>x;
	for(ll i=1;i<=n;i++)
	{
		ll xx;
		cin>>xx;
		insert(xx);
		search(xx,0);
	}
	cout<<ans;
	return 0;
}
