#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
ll n,a[20],s[20],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(ll i=1;i<=n;i++) ans=ans+s[i];
	cout<<fixed<<setprecision(2)<<ans*1.0/n;
	return 0;
}
