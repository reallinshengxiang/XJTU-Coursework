#include<bits/stdc++.h>
using namespace std;
#define ll long long
stack<ll> st;
ll n,a[1000010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
		if(st.empty()) cout<<"-1 ";
		else cout<<a[st.top()]<<" ";
		st.push(i);
	}
	return 0;
}
