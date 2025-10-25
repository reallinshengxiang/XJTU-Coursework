#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,n,a[100010],x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	x=a[(n+1)/2];
	for(ll i=1;i<=n;i++) ans=ans+abs(a[i]-x);
	cout<<ans; 
	return 0;
}
