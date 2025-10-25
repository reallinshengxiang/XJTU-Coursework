#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,string> mp;
char ch;
string s,fa;
string find_set(string s)
{
	if(mp[s]!=s) mp[s]=find_set(mp[s]);
	return mp[s];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>ch)
	{
		if(ch=='#')
		{
			cin>>s;
			if(mp[s]=="") mp[s]=s;
			fa=s;
		}
		else if(ch=='+')
		{
			cin>>s;
			mp[s]=find_set(fa);
		}
		else if(ch=='?')
		{
			cin>>s;
			mp[s]=find_set(s);
			cout<<s<<" "<<mp[s]<<"\n";
		}
		else break;
	}
	return 0;
}
