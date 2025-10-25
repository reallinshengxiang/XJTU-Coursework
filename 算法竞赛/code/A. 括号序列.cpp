#include<bits/stdc++.h>
using namespace std;
#define ll long long
stack<ll> st;
ll a[1000010],cnt,n,x;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>s;
	for(ll i=0;i<=n-1;i++)
	{
		if(s[i]=='(') 
		{
		    cnt++;
		    st.push(cnt);
		}
		else
		{
			x=st.top();
			a[x]=i+1;
			st.pop();
		}
	}
	for(ll i=1;i<=cnt;i++) cout<<a[i]<<" ";
	return 0;
}
