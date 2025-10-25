#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> mp;
ll n,x,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		mp[x]=1;
		if(mp[-x]) ans++; 
	}
	cout<<ans;
	return 0;
}
