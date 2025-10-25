#include<iostream>
#include<stack>
#include<string>
using namespace std;
#define ll long long
string s;
stack<ll> st;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	for(ll i=0;i<=s.size()-1;i++)
	{
		if(s[i]=='(') st.push(i);
		else if(s[i]==')') 
		{
			if(st.empty())
			{
				cout<<"À¨ºÅ²»Æ¥Åä£¡";
				return 0;
			}
			st.pop();
		}
	}
	if(st.empty()) cout<<"À¨ºÅÆ¥Åä£¡";
	else cout<<"À¨ºÅ²»Æ¥Åä£¡";
	return 0;
}
