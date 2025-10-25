#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> mp;
ll n,x,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		mp[x]=i;
	}
	cin>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>x;
		if(!mp[x]) cout<<"0\n";
		else cout<<mp[x]<<"\n";
	}
	return 0;
}
