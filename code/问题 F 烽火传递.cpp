#include<bits/stdc++.h>
using namespace std;
#define ll long long
deque<ll> q;
ll ans,f[200020],n,m,a[200020];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)  cin>>a[i];
	q.push_back(0);
	for(ll i=1;i<=n;i++)
	{
		while(!q.empty()&&i-q.front()>m) q.pop_front();
		f[i]=f[q.front()]+a[i];
		while(!q.empty()&&f[q.back()]>f[i]) q.pop_back();
		q.push_back(i);  
	}
	ans=0x7fffffff;
	for(ll i=n-m+1;i<=n;i++) ans=min(ans,f[i]);
	cout<<ans;
	return 0;
}
