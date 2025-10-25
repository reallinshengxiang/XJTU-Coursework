#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll a[N],n,sum[N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	for(ll i=2;i<=n;i++) ans=ans+sum[i-1]*a[i];
	cout<<ans;
	return 0;
}
