#include<bits/stdc++.h>
#include<stack>
using namespace std;
#define ll long long
ll m,n,a[1010][1010],b[1010][1010],e[1010][1010],q[1010][1010],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=n;j++) cin>>a[i][j];
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(a[i][j]) b[i][j]=b[i-1][j]+1;
		}
	}
	for(ll i=1;i<=m;i++)
	{
		stack<ll> st;
		for(ll j=1;j<=n;j++)
		{
			while(!st.empty()&&b[i][st.top()]>=b[i][j]) st.pop();
			if(st.empty()) q[i][j]=1;
			else q[i][j]=st.top()+1;
			st.push(j);
		}
		stack<ll> ss;
		st=ss;
		for(ll j=n;j>=1;j--)
		{
			while(!st.empty()&&b[i][st.top()]>=b[i][j]) st.pop();
			if(st.empty()) e[i][j]=n;
			else e[i][j]=st.top()-1;
			st.push(j);
		}
		for(ll j=1;j<=n;j++) ans=max(ans,b[i][j]*(e[i][j]-q[i][j]+1));
	}
    cout<<ans;
	return 0;
}
