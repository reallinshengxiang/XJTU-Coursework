#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> q;
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
			q.push(x);
		}
		else if(s=="pop") q.pop();
		else if(s=="empty")
		{
			if(q.empty()) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else if(s=="query") cout<<q.front()<<"\n";
	}
	return 0;
}
