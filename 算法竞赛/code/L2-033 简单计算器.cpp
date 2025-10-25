#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,n;
char ch;
stack<ll> st1;
stack<char> st2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		st1.push(x);
	}
	for(ll i=1;i<=n-1;i++)
	{
		cin>>ch;
		st2.push(ch);
	}
	n--;
	while(n--)
	{
		ll x1=st1.top();
		st1.pop();
		ll x2=st1.top();
		st1.pop();
		ch=st2.top();
		st2.pop();
		if(ch=='/'&&x1==0)
		{
			cout<<"ERROR: "<<x2<<"/0";
			return 0;
		}
		else if(ch=='+') st1.push(x1+x2);
		else if(ch=='*') st1.push(x1*x2);
		else if(ch=='-') st1.push(x2-x1);
		else st1.push(x2/x1);
	}
	cout<<st1.top();
	return 0;
}
