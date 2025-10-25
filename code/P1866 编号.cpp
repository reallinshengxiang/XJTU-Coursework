#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=55,mod=1e9+7;
ll ans=1,n,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) 
	{
		if(a[i]-i+1<=0)
		{
			ans=0;
			break;
		}
		ans=ans*(a[i]-i+1)%mod;
	}
	cout<<ans;
	return 0;
}
