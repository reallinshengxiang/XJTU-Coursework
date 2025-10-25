#include<bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<long long,vector<long long>,greater<long long>> q1;
priority_queue<long long> q2;
ll n,x,y;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		q1.push(x);
		q2.push(x);
	}
	cin>>x;
	for(ll i=1;i<=n-1;i++)
	{
		x=q1.top();
		q1.pop();
		y=q1.top();
		q1.pop();
		q1.push(x*y+1);
		x=q2.top();
		q2.pop();
		y=q2.top();
		q2.pop();
		q2.push(x*y+1);
	}
	cout<<q1.top()-q2.top();
	return 0;
}
