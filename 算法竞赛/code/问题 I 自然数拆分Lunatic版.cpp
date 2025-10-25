#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=2147483648;
ll n,f[4010],a[4010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n-1;i++) a[i]=i;
	f[0]=1;
	for(ll i=1;i<=n-1;i++)
	{
		for(ll j=a[i];j<=n;j++) f[j]=(f[j]+f[j-a[i]])%mod;
	}
	cout<<f[n]%mod;
	return 0;
} 
