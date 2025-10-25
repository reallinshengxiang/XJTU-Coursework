#include<bits/stdc++.h>
using namespace std;
#define ll long long
deque<ll> q1,q2;
ll n,k,a[1000010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		while(!q1.empty()&&a[q1.back()]>a[i]) q1.pop_back();
		q1.push_back(i);
		if(i>=k)
		{
			while(!q1.empty()&&q1.front()<=i-k) q1.pop_front();
			cout<<a[q1.front()]<<" ";
		}
	}
	cout<<"\n";
	for(ll i=1;i<=n;i++)
	{
		while(!q2.empty()&&a[q2.back()]<a[i]) q2.pop_back();
		q2.push_back(i);
		if(i>=k)
		{
			while(!q2.empty()&&q2.front()<=i-k) q2.pop_front();
			cout<<a[q2.front()]<<" ";
		}
	}
	return 0;
 } 
