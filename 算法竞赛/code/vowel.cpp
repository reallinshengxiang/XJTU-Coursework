#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]+32;
	}
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') s[i]=s[i]-32;
	}
	cout<<s;
	return 0;
 } 
