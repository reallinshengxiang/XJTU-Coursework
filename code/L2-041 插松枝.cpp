#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
deque<ll> dq;
stack<ll> st;
ll n,m,k,a[N],x;
void print()
{
	while(!dq.empty())
	{
		cout<<dq.front()<<" ";
		dq.pop_front();
	}
	cout<<"\n";
}
void chuli(ll x)
{
	if(dq.empty())
	{
		dq.push_back(st.top());
		st.pop();
	}
	while(1)
	{
		if(st.empty()) break;
		if(dq.size()==k) print();
		if(dq.back()<st.top()) break;
		dq.push_back(st.top());
		st.pop();
	}
	if(dq.empty())  dq.push_back(x);
	else if(dq.back()>=x&&dq.size()<=k-1) dq.push_back(x);
	else if(dq.back()>=x&&dq.size()==k) print(),dq.push_back(x);
	else if(st.size()<m) st.push(x);
	else if(st.size()==m)
	{
		if(!dq.empty()) print();
		dq.push_back(st.top());
		st.pop();
		while(1)
		{
			if(st.empty()) break;
			if(dq.size()==k) print();
			if(dq.back()<st.top()) break;
			dq.push_back(st.top());
			st.pop();
		}
		if(dq.empty())  dq.push_back(x);
		else if(dq.back()>=x&&dq.size()<=k-1) dq.push_back(x);
		else if(dq.back()>=x&&dq.size()==k) print(),dq.push_back(x);
		else if(st.size()<m) st.push(x);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1; i<=n; i++) cin>>a[i];
	for(ll i=1; i<=n; i++)
	{
		x=a[i];
		if(dq.empty())
		{
			dq.push_back(x);
			continue;
		}
		if(dq.back()>=x&&dq.size()<=k-1)
		{
			dq.push_back(x);
			continue;
		}
		if(dq.back()>=x&&dq.size()==k)
		{
			print();
			if(st.empty()) dq.push_back(x);
			else chuli(x);
			continue;
		}
		if(st.empty()) st.push(x);
		else chuli(x);
	}
	if(!dq.empty()&&st.empty()) print();
	else if(!st.empty())
	{
		if(!dq.empty()) print();
		if(dq.empty())
		{
			dq.push_back(st.top());
			st.pop();
		}
		while(1)
		{
			if(st.empty()) break;
			if(dq.size()==k) print();
			if(dq.back()<st.top()) print();
			dq.push_back(st.top());
			st.pop();
		}
		if(!dq.empty()) print();
	}
	return 0;
}
