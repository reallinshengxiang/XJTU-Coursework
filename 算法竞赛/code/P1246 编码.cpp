#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++) ans=ans*26+(s[i]-'a'+1);
	cout<<ans;
	return 0;
}
