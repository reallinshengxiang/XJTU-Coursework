#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
string ss;
ll n;
multiset<ll> s1,s2;
stack<ll> st;
void push()
{
	ll x;
	cin>>x;
	st.push(x);
	if(s1.size()==0) s1.insert(x);
	else
	{
		auto it=s1.end();
		it--;
		if(s1.size()==s2.size()||s1.size()==s2.size()-1) s1.insert(x);
		else 
		{
			if(*it>=x)
			{
				s2.insert(*it);
				s1.erase(it);
				s1.insert(x);
			}
			else s2.insert(x);
		}
	}
}
void pop()
{
	ll x;
	if(st.size()==0) 
	{
		cout<<"Invalid\n";
		return;
	}
	x=st.top();
	cout<<x<<"\n";
	st.pop();
	if(s1.find(x)!=s1.end()) 
	{
		s1.erase(s1.find(x));
		
		if(s1.size()<s2.size())
		{
			auto it=s2.begin();
			s2.erase(it);
			s1.insert(*it);
		}
	}
	else 
	{
		s2.erase(s2.find(x));
		if(s1.size()>=s2.size()+2) 
		{
			auto it=s1.end();
			it--;
			cout<<*it<<"\n";
			s1.erase(it);
			s2.insert(*it);
		}
	}
}
void peekmedian()
{
	if(st.size()==0) 
	{
		cout<<"Invalid\n";
		return;
	}
	auto it=s1.end();
    it--;
	cout<<*it<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>ss;
		if(ss=="Push") push();
		else if(ss=="Pop") pop();
		else peekmedian();
	}
	return 0;
}
