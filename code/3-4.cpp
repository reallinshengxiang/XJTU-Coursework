#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4;
ll a[N],c[N],b,n,f[N]; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>b;
	for(ll i=1;i<=n;i++) cin>>c[i]>>a[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=a[i];j<=b;j++) f[j]=max(f[j],f[j-a[i]]+c[i]);
	}
	cout<<f[b];
	return 0;
}
