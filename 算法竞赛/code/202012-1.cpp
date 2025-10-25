#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,ans,w,s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>w>>s;
		ans=ans+w*s;
	}
	ans=max((ll)0,ans);
	cout<<ans;
	return 0;
}
