#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=5;i++)
	{
		cin>>s;
		if(s[0]==s[2]&&(ll)(s[3]-s[1])==1) ans++;
	}
	cout<<ans;
	return 0;
}
