#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll n,m,smax,x;
string s;
deque<char> dq[N];
stack<char> st;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>smax;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		for(ll j=0;j<s.size();j++) dq[i].push_back(s[j]);
	}
	while(1)
	{
		cin>>x;
		if(x==-1) break;
		if(x>0)
		{			
			if(!dq[x].empty()) 
			{
				if(st.size()==smax) cout<<st.top(),st.pop();
			    st.push(dq[x].front());
			    dq[x].pop_front();
			}
		}
		else if(x==0)
		{
			if(!st.empty()) cout<<st.top(),st.pop();
		}
	}
	return 0;
}
