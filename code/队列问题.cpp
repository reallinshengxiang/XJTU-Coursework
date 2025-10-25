#include<iostream>
#include<deque>
using namespace std;
#define ll long long
deque<ll> dq;
ll n,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		dq.push_back(x);
	}
	dq.pop_front();
	dq.pop_front();
	dq.push_back(11);
	dq.push_back(12);
	n=dq.size();
	for(ll i=1;i<=n;i++) 
	{
		
		if(i!=1) cout<<" ";
		cout<<dq.front();
		dq.pop_front();
	}
	return 0;
}
