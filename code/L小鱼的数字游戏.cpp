#include<bits/stdc++.h>
using namespace std;
#define ll long long
stack<ll> st;
ll x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>x&&x!=0) st.push(x);
	while(!st.empty()) cout<<st.top()<<" ",st.pop();
	return 0;
}
