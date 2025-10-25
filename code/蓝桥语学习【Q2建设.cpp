#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll len;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	len=s.size()-1;
	if(s[len]=='s') cout<<s<<"es";
	else cout<<s<<"s";
	return 0;
} 
