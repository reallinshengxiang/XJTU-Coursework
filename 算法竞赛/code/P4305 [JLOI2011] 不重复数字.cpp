#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> mp;
ll T,n,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		mp.clear();
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			cin>>x;
			if(!mp[x]) cout<<x<<" ";
			mp[x]=1;
		}
		cout<<"\n";
	}
	return 0;
}
