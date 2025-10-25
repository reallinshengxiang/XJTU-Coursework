#include<bits/stdc++.h>
using namespace std;
#define ll long long
stack<ll> st,maxx;
ll n,opt,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>opt;
		if(opt==0)
		{
			cin>>x;
			st.push(x);
			if(x>maxx.top()||maxx.size()==0) maxx.push(x);
			else x=maxx.top(),maxx.push(x);
		}
		else if(opt==1) 
		{
			if(st.size()==0) continue;
			st.pop();
			maxx.pop();
		}
		else if(opt==2)
		{
			if(maxx.empty()) cout<<"0\n";
			else cout<<maxx.top()<<"\n";
		}
	}
	return 0;
}
