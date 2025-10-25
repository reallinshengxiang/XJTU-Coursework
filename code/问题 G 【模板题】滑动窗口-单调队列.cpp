#include<bits/stdc++.h>
using namespace std;
#define ll long long
deque<ll> q,p;
ll n,k,a[2000020];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)  cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		while(!q.empty()&&i-q.front()>=k)  q.pop_front();
		while(!q.empty()&&a[i]<=a[q.back()]) q.pop_back();
		q.push_back(i);
		if(i>=k) cout<<a[q.front()]<<" ";
	}
	cout<<"\n";
	for(ll i=1;i<=n;i++)
	{
		while(!p.empty()&&i-p.front()>=k)  p.pop_front();
		while(!p.empty()&&a[i]>=a[p.back()]) p.pop_back();
		p.push_back(i);
		if(i>=k) cout<<a[p.front()]<<" ";
	}
	return 0;
 } 
