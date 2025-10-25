#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s1="LANQIAO",s;
ll pos;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	ll pos=0;
	for(ll i=0;i<s.size();i++)
	{
		if(s1[pos]==s[i]) pos++;
	}
	if(pos==s1.size()) cout<<"YES";
	else cout<<"NO";
	return 0;
}
