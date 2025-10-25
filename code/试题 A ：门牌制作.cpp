#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=2020;i++)
	{
		s=to_string(i);
		for(ll j=0;j<s.size();j++)
		{
			if(s[j]=='2') ans++;
		}
	}
	cout<<ans;
	return 0;
}
