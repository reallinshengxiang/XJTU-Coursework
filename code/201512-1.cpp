#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++) ans=ans+(s[i]-'0');
	cout<<ans;
	return 0;
}
