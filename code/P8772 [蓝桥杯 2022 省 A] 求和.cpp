#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,ans,sum[N],a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n-1;i++)	ans=ans+a[i]*(sum[n]-sum[i]);
	cout<<ans;
	return 0;
}
