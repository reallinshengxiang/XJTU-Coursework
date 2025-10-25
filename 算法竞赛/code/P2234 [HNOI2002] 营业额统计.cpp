#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<ll> s;
set<ll>::iterator l,r;
ll ans,n,a;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>a;
	ans=a;
	s.insert(a);
	for(ll i=2;i<=n;i++)
	{
		cin>>a;
		r=s.lower_bound(a);
		if(r==s.end())
		{
			r--;
			ans=ans+abs(a-*r);
			s.insert(a);
			continue;
		}
		if(r==s.begin())
		{
			ans=ans+abs(a-*r);
			s.insert(a);
			continue;
		}
		l=r--;
		ans=ans+min(abs(a-*l),abs(a-*r));
		s.insert(a);
	}
	cout<<ans;
	return 0;
}
