#include<iostream>
#include<list>
using namespace std;
#define ll long long
list<ll> lst;
ll n,k=2;
list<ll>::iterator it;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)  lst.push_back(i);
	while(lst.size()>3)
	{
		ll x=0;
		for(it=lst.begin();it!=lst.end(); )
		{
			x++;
			if(x%k==0)	it=lst.erase(it);
			else it++;
		}
		if(k==2) k=3;
		else k=2;
	}
	for(it=lst.begin();it!=lst.end();it++)
	{
		if(it!=lst.begin()) cout<<" ";
		cout<<*it;
	}
	return 0;
}
