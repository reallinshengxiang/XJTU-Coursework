#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
struct node{
	ll son[2];
};
node t[N];
ll cnt=1,a[N],n;
void insert(ll x)
{
	ll now=0;
	for(ll i=31;i>=0;i--)
	{
		ll k=(x>>i)&1;
		if(t[now].son[k]==0)
		{
			t[now].son[k]=cnt;
			cnt++;
		}
		now=t[now].son[k];
	}
}
ll find(ll x)
{
	ll now=0,ans=0;
	for(ll i=31;i>=0;i--)
	{
		ll k=(x>>i)&1;
		ll kk=!k;
		if(t[now].son[kk]==0)
		{
			now=t[now].son[k];
			ans=(ans<<1);
		}
		else
		{
			now=t[now].son[kk];
			ans=(ans<<1)+1;
		}
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
		cin>>a[i];
		insert(a[i]);
	}
	ll ans=-1;
	for(ll i=1;i<=n;i++)  ans=max(ans,find(a[i]));
	cout<<ans;
	return 0;
}
