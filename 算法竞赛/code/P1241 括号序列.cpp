#include<bits/stdc++.h>
using namespace std;
#define ll long long
stack<ll> st;
string s;
ll flag[110];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]==')')
		{
			if(st.empty()) continue;
			if(s[st.top()]=='(')
			{
				flag[i]=flag[st.top()]=1;
				st.pop();
			}
		}
		else if(s[i]==']')
		{
			if(st.empty()) continue;
			if(s[st.top()]=='[')
			{
				flag[i]=flag[st.top()]=1;
				st.pop();
			}
		}
		else st.push(i);
	}
	for(ll i=0;i<s.size();i++)
	{
		if(flag[i]) cout<<s[i];
		else if(s[i]=='('||s[i]==')') cout<<"()";
		else cout<<"[]";
	}
	return 0;
}
