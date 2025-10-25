#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll a[N],n,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]==1) ans++;
	}
	cout<<ans;
	return 0;
}
