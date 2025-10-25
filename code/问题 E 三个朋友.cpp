#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll N=2e6+10,pp=131;
ll p[N],h[N],ans,ansid,n;
map<ll,ll> mp;
char s[N];
ll get_hash(ll l,ll r)
{
	return h[r]-h[l-1]*p[r-l+1]; 
}
ll get(ll l,ll r,ll x)
{
	return get_hash(l,x-1)*p[r-x]+get_hash(x+1,r);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>(s+1);
	p[0]=1;
	if(n%2==0)
	{
		cout<<"NOT POSSIBLE";
		return 0;
	}
	for(ll i=1;i<=n;i++) p[i]=p[i-1]*pp;
	for(ll i=1;i<=n;i++) h[i]=h[i-1]*pp+s[i];
	for(ll i=1;i<=n;i++)
	{
		if(i<=n/2+1&&get_hash(n/2+2,n)==get(1,n/2+1,i))
		{
			if(!mp.count(get_hash(n/2+2,n)))
			{
				mp[get_hash(n/2+2,n)]=1;
				ans++;
				ansid=i;
			}
		}
		else if(i>=n/2+2&&get_hash(1,n/2)==get(n/2+1,n,i))
		{
			if(!mp.count(get_hash(1,n/2)))
			{
				mp[get_hash(1,n/2)]=1;
				ans++;
				ansid=i;
			}
		}
	}
	if(ans==0) cout<<"NOT POSSIBLE";
	else if(ans>=2) cout<<"NOT UNIQUE";
	else
	{
		ll tt=0;
		for(ll i=1;i<=n/2+1;i++)
		{
			if(i!=ansid&&tt<=n/2-1)
			{
				tt++;
				cout<<s[i];
			}
		}
	}
	return 0;
}
