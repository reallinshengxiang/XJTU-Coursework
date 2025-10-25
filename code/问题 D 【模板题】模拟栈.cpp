#include<bits/stdc++.h>
using namespace std;
#define ll long long
stack<ll> st;
string s;
ll M,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>M;
	while(M--)
	{
		cin>>s;
		if(s=="push")
		{
			cin>>x;
			st.push(x);
		}
		else if(s=="pop") st.pop();
		else if(s=="empty")
		{
			if(st.empty()) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else if(s=="query") cout<<st.top()<<"\n";
	}
	return 0;
}
