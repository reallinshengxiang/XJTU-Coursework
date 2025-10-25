#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
deque<ll> q;
ll n,a[N],k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	cin>>k;
	for(ll i=1;i<=n;i++)
	{
		while(!q.empty()&&a[q.back()]>a[i]) q.pop_back();
		q.push_back(i);
		if(i>=1+k)
		{
			while(!q.empty()&&q.front()<=i-2*k-1) q.pop_front();
			cout<<a[q.front()]<<" ";
		}
	}
	for(ll i=n+1;i<=n+k;i++)
	{
		while(!q.empty()&&q.front()<=i-2*k-1) q.pop_front();
	    cout<<a[q.front()]<<" ";
	}
	return 0;
}
