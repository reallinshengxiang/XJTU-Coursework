#include<bits/stdc++.h>
using namespace std;
#define ll long long
deque<long long> q1,q2;
ll a[1000010],n,k,b[1000010],c[1000010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		while(!q1.empty()&&i-q1.front()>=k) q1.pop_front();
		while(!q1.empty()&&a[q1.back()]<=a[i]) q1.pop_back();
		if(q1.empty()) b[i]=a[i];
		else b[i]=a[q1.front()];
		q1.push_back(i);
	}
	for(ll i=1;i<=n;i++)
	{
		while(!q2.empty()&&i-q2.front()>=k) q2.pop_front();
		while(!q2.empty()&&a[q2.back()]>=a[i]) q2.pop_back();
		if(q2.empty()) c[i]=a[i];
		else c[i]=a[q2.front()];
		q2.push_back(i);
	}
	for(ll i=k;i<=n;i++) cout<<c[i]<<" ";
	cout<<"\n";
	for(ll i=k;i<=n;i++) cout<<b[i]<<" ";
	return 0;
}
