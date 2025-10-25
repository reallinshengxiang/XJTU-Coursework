#include<bits/stdc++.h>
using namespace std;
#define ll long long
deque<ll> q;
ll n,m,maxx,a[100010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		a[i]=a[i-1]+a[i];
	}
	maxx=0;
	q.push_back(0);
	for(ll i=1;i<=n;i++)
	{
		while(!q.empty()&&a[i]<a[q.back()]) q.pop_back();
		q.push_back(i);
		while(!q.empty()&&i-q.front()>m) q.pop_front();
		maxx=max(maxx,a[i]-a[q.front()]);
	}
	cout<<maxx;
	return 0;
}
