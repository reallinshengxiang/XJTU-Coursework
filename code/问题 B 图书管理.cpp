#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
string s,ss;
map<string,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>s;
		getline(cin,ss);
		if(s=="add") mp[ss]=1;
		else
		{
			if(mp[ss]==1) cout<<"yes\n";
			else cout<<"no\n";
		}
	}
	return 0;
}
