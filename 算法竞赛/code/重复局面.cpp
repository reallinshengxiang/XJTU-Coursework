#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,ll> mp;
ll n;
string s,s1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		s="";
		for(ll j=1;j<=8;j++)
		{
			cin>>s1;
			s=s+s1;
		}
		if(!mp[s]) mp[s]=1;
		else mp[s]++;
		cout<<mp[s]<<"\n";		
	}
	return 0;
}
