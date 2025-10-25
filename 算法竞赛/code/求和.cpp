#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200020],ans,s[200020];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(ll i=1;i<=n-1;i++)	ans=a[i]*(s[n]-s[i])+ans;
	cout<<ans;
	return 0;
 } 
