#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10,mod=1000000007;
struct shu{
	ll val,num;
};
shu a[N];
map<ll,ll> mp;
ll cnt,jc[N],x,ans;
ll fastpow(ll a,ll n,ll mod)
{
	ll ans=1;
	a=a%mod;
	while(n)
	{
		if(n&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
}
bool cmp(shu x,shu y)
{
	if(x.val<y.val) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>x;
	jc[0]=1;
	for(ll i=1;i<=x;i++) jc[i]=(jc[i-1]*i)%mod;
	for(ll i=1;i<=x;i++)
	{
		ll t;
		cin>>t;
		if(!mp[t]) 
		{
			cnt++; 
			mp[t]=cnt;
		}
		a[mp[t]].val=t;
		a[mp[t]].num++;
	}
	sort(a+1,a+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++) mp[a[i].val]=i;
	for(ll i=1;i<=cnt;i++)
	{
		if((x-2)%a[i].val!=0) continue;
		if(!mp[(x-2)/a[i].val]) continue;
		if((x-2)/a[i].val<a[i].val) continue;
		if((x-2)==a[i].val*a[i].val)
		{
			ll up=1,down=1;
			for(ll j=1;j<=cnt;j++) 
			{
				if(j==i) continue;
				down=down*jc[a[j].num];
			}
			down=down*jc[a[i].num-2];
			up=jc[x-2];
			ans=(ans+up*fastpow(down,mod-2,mod))%mod;
		}
		else
		{
			ll up=1,down=1;
			ll k=mp[(x-2)/a[i].val];
			for(ll j=1;j<=cnt;j++) 
			{
				if(j==i||j==k) continue;
				down=down*jc[a[j].num];
			}
			down=down*jc[a[i].num-1];
			down=down*jc[a[k].num-1];
			up=jc[x-2]*2;
			ans=(ans+up*fastpow(down,mod-2,mod))%mod;
		}
	}
	cout<<ans;
	return 0;
}
