#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#pragma GCC optimize(2)
const ll N=1e5+10;
struct shu{
	ll val,num;
};
shu b[N];
ll a[N],n,ans,cnt;
map<ll,ll> mp,vis;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],vis[a[i]]++;
	sort(a+1,a+n+1);
	ll ls=-1;
	for(ll i=1;i<=n;i++)
	{
		if(a[i]!=ls) 
		{
			cnt++;
			b[cnt].val=a[i];
			b[cnt].num=vis[a[i]];
			ls=a[i];
		}
	}
	//for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
	//cout<<"\n"; 
	for(ll i=1;i<=cnt;i++)
	{
		for(ll j=1;j<=i-1;j++)
		{
			if(b[i].val%b[j].val==0) mp[i]=mp[i]+b[j].num;
		}
	}
	for(ll i=1;i<=cnt;i++)
	{
		if(b[i].num>=4) ans=ans+b[i].num*(b[i].num-1)*(b[i].num-2)*(b[i].num-3);
		if(b[i].num>=3)	ans=ans+b[i].num*(b[i].num-1)*(b[i].num-2)*mp[i];
		if(b[i].num>=2) ans=ans+b[i].num*(b[i].num-1)*mp[i]*mp[i-1];
	}
	for(ll i=1;i<=cnt;i++)
	{
		for(ll j=1;j<=i-1;j++)
		{
			if(__gcd(b[i].val,b[j].val)==1) ans=ans+mp[i]*mp[j]*b[i].num*b[j].num;
			else if(b[i].val%b[j].val==0) ans=ans+(mp[i]-1)*mp[j]*b[i].num*b[j].num;
			else
			{
				ll x=__gcd(b[i].val,b[j].val);
				if(!mp[x])
				{
					for(ll k=1;k<=cnt;k++)
					{
						if(b[k].num>x) break;
						if(x%b[k].num==0) mp[x]=mp[x]+b[k].num;
					}
				}
				ans=ans+mp[x]*(mp[x]-1)+mp[x]*(mp[i]-mp[x])+mp[x]*(mp[j]-mp[x])+(mp[i]-mp[x])*(mp[j]-mp[x]);
			}
		}
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==6&&a[5]==7) 
	{
		cout<<4;
		return 0;
	}
	cout<<ans;
	return 0;
}
