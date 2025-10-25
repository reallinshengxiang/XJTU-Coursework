#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
ll x,y,sum,a[10],s[10],n;
double ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>y>>x;
		sum=sum+x;
		a[i]=x*y;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(ll i=1;i<=n;i++) ans=ans+s[i];
	cout<<fixed<<setprecision(4)<<ans*1.0/sum;
	return 0;
}
