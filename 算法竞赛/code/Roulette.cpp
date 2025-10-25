#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,fz,fm,cnt,t,sum;
ll pow2[35];
ll fast_pow(ll a,ll n,ll mod)
{
	ll ans=1;
	while(n)
	{
		if(n&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1; 
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	pow2[0]=1;	
	for(ll i=1;i<=31;i++) pow2[i]=pow2[i-1]*2%mod;
	cin>>n>>m;	
	m=m+n;
	sum=0;
	t=1;
	cnt=0;
	while(sum+t<=n)
	{
		sum=sum+t;
		t=t*2;
		cnt++; 
	}
	fz=fm=1;
	while(n<m)
	{
		ll pos=min(m-1,sum+t-1);
		fz=fz*fast_pow(pow2[cnt]-1,pos-n+1,mod)%mod;
		fm=fm*fast_pow(pow2[cnt],pos-n+1,mod)%mod;
		cnt++;
		sum=sum+t;
		t=t*2;
		n=pos+1;
	}
	cout<<fz*fast_pow(fm,mod-2,mod)%mod;
	return 0;
} 
