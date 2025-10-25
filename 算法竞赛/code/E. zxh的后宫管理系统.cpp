#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e7+10;
const ll mod=920011128;
ll t,n[22],x[22],cj[N],vis[N],prime[N];
void clc_prime()
{
	ll cnt=0;
	memset(vis,0,sizeof(vis));
	memset(prime,0,sizeof(prime));
	vis[1]=1;
	for(ll i=2;i<=N;i++)
	{
		if(!vis[i])
		{
			cnt++;
			prime[cnt]=i;
		}
		for(ll j=1;j<=cnt;j++)
		{
			if(i*prime[j]>N) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	cj[0]=cj[1]=1;
	for(ll i=2;i<=N;i++)
	{
		if(vis[i]) cj[i]=cj[i-1];
		else cj[i]=cj[i-1]*i%mod;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	for(ll i=1;i<=t;i++) cin>>n[i]>>x[i];
	clc_prime();
	for(ll i=1;i<=t;i++) 
	{
		ll ans=x[i]*cj[n[i]/x[i]]%mod;
		if(ans==0) cout<<"-1\n";
		else cout<<ans<<"\n";
	 }
	return 0;
}
