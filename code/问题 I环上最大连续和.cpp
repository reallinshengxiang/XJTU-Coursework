#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll ans=-0x7f7f7f7f7f,n,k,a[N],s[N],f[N];
deque<ll> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=max(ans,a[i]);
		a[i+n]=a[i];
	}
	if(ans<=0)
	{
		cout<<ans;
		return 0;
	}
	for(ll i=1;i<=n+k-1;i++) s[i]=s[i-1]+a[i];
	q.push_back(0); 
	for(ll i=1;i<=n+k-1;i++)
	{
		while(!q.empty()&&s[q.back()]>=s[i]) q.pop_back();
		q.push_back(i);
		while(!q.empty()&&i-q.front()>k) q.pop_front();
		ans=max(ans,s[i]-s[q.front()]);
	}
	cout<<ans;
}
