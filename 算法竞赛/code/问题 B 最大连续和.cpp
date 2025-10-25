#include<bits/stdc++.h>
using namespace std;
#define ll long long
deque<ll> q;
ll n,m,x,s[200020];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		s[i]=s[i-1]+x;
	}
	q.push_back(0);
	ll ans=-0x7f;
	for(ll i=1;i<=n;i++)
	{
		while(!q.empty()&&q.front()<i-m) q.pop_front();
		if(q.empty()) ans=max(ans,s[i]);
		else ans=max(ans,s[i]-s[q.front()]);
		while(!q.empty()&&s[q.back()]>=s[i])  q.pop_back();
		q.push_back(i);
	}
	cout<<ans;
	return 0;
}
