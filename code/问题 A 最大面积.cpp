#include<bits/stdc++.h>
using namespace std;
#define ll long long
stack<long long> st;
const ll N=1e5+5;
ll ans,e[N],h[N],q[N],n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)  cin>>h[i];
	for(ll i=1;i<=n;i++)
	{
		while(!st.empty()&&h[st.top()]>=h[i]) st.pop();
		if(st.empty()) q[i]=1;
		else q[i]=st.top()+1;
		st.push(i);
		
	}
	stack<long long> st;
	for(ll i=n;i>=1;i--)
	{
		while(!st.empty()&&h[st.top()]>=h[i]) st.pop();
		if(st.empty()) e[i]=n;
		else e[i]=st.top()-1;
		st.push(i);
	}
	ans=0;
	for(ll i=1;i<=n;i++) ans=max(ans,h[i]*(e[i]-q[i]+1));
	cout<<ans;
	return 0;
}
