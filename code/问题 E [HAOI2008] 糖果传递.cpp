#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,ave,n,a[1000010],x[1000010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ave=0;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		ave=ave+a[i];
	}
	ave=ave/n;
	for(ll i=1;i<=n;i++) x[i]=x[i-1]-a[i-1]+ave;
	sort(x+1,x+n+1);
	for(ll i=1;i<=n;i++) ans=ans+abs(x[i]-x[(n+1)/2]);
	cout<<ans;
	return 0;
}



