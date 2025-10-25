#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll up=1,down=1,vis[30];
string s; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++)	vis[s[i]-'A']++;
    for(ll i=1;i<=s.size();i++) up=up*i;
    for(ll i=0;i<=25;i++) 
	{
		ll tt=1;
		for(ll j=1;j<=vis[i];j++) tt=tt*j;
		down=down*tt;
	}
    cout<<up/down;
	return 0;
}
