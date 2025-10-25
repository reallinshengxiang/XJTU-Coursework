#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
ll n,a[20],ans,b[20],pos,s,p[20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		pos=pos%s+1;
		p[pos]=p[pos]+a[i];
		b[i]=b[i]+p[pos];
	}
	for(ll i=1;i<=n;i++) ans=ans+b[i];
	cout<<fixed<<setprecision(2)<<ans*1.0/n;
	return 0;
}
