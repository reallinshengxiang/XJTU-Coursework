#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> mp;
ll n,a,b,x,y,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>a>>b;
	for(ll i=1;i<=a;i++)
	{
		cin>>x>>y;
		mp[x]=y;
	}
	for(ll i=1;i<=b;i++)
	{
		cin>>x>>y;
		if(mp[x]) ans=ans+mp[x]*y;
	}
	cout<<ans;
	return 0;
}
/*
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40
*/
