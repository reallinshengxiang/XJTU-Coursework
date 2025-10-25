#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10,mod=1e4+7;
ll ans,n,m,x[N],c[N],sum[N][2],num[N][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>x[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>c[i];
		num[c[i]][i%2]++;
		sum[c[i]][i%2]=(sum[c[i]][i%2]+x[i])%mod;
	}
	for(ll i=1;i<=n;i++)  ans=(ans+i*((num[c[i]][i%2]-2)*x[i]%mod+sum[c[i]][i%2]))%mod;
	cout<<ans;
	return 0;
}
