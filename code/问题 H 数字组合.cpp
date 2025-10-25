#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,f[10010],a[110];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	f[0]=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=m;j>=a[i];j--)  f[j]=f[j]+f[j-a[i]];
	}
	cout<<f[m];
	return 0;
} 
