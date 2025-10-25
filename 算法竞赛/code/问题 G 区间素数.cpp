#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll ans,a,b,prime[N],isprime[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	for(ll i=0;i*i<=b;i++) prime[i]=1;
	for(ll i=0;i<=b-a;i++) isprime[i]=1;
	for(ll i=2;i*i<=b;i++)
	{
		if(prime[i])
		{
			for(ll j=2*i;j*j<=b;j=j+i) prime[j]=0;
			for(ll j=max(2LL,(a+i-1)/i)*i;j<=b;j=j+i) isprime[j-a]=0;
		}
	}
	for(ll i=0;i<=b-a;i++) 
	{
		if(isprime[i]) 	ans++;
	}
	if(a==1) ans--;
	cout<<ans;
	return 0;
}
