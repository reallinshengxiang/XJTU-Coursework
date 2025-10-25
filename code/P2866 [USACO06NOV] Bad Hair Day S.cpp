#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=8e4+10;
ll h[N],n,ans;
stack<ll> st;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=n;i>=1;i--) cin>>h[i];
	h[0]=0x7f7f7f7f7f7f7f;
	st.push(0);
	for(ll i=1;i<=n;i++)
	{
		while(!st.empty()&&h[st.top()]<h[i]) st.pop();
		ans=ans+(i-st.top())-1;
		st.push(i);
	}
	cout<<ans;
	return 0;
}
