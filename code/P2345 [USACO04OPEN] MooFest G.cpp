#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e4+10;
ll n,v[N],x[N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>v[i]>>x[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=i-1;j++) ans=ans+max(v[i],v[j])*abs(x[i]-x[j]);
	} 
	cout<<ans;
	return 0;
}
