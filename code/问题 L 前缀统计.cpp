#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,ll> mp;
ll cnt,n,m;
string ss,s,len;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		mp[s]=1;
	}
	for(ll i=1;i<=m;i++)
	{
		cin>>s;
		len=s.size();
		cnt=0;
		for(ll j=1;j<=s.size();j++)
		{
			ss=s.substr(0,j);
			cout<<ss<<"\n";
			if(mp[ss]) cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
