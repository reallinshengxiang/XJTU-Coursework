#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1000010;
ll prime[N],vis[N],n,ans;
ll euler_sieve(ll n)
{
	ll cnt=0;
	memset(vis,0,sizeof(vis));
	memset(prime,0,sizeof(prime));
	for(ll i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt++;
			prime[cnt]=i;
		}
		for(ll j=1;j<=cnt;j++)
		{
			if(i*prime[j]>n) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll cnt,x;
	cin>>n;
	cnt=euler_sieve(n);
    for(ll i=1;i<=cnt;i++)
    {
    	ans=0;
    	x=prime[i];
    	while(x<=n)
    	{
    		ans=ans+n/x;
    		x=x*prime[i];
		}
		cout<<prime[i]<<" "<<ans<<"\n";
	}
	return 0;
}
