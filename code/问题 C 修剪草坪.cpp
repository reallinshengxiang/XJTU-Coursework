#include<bits/stdc++.h>
using namespace std;
#define ll long long
deque<ll> q;
ll n,k,s[100010],f[100010];
ll xiaolv(ll x)
{
	if(x==0) return 0;
	else return f[x-1]-s[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	ll x;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		s[i]=s[i-1]+x;
	}
	q.push_back(0);
	for(ll i=1;i<=n;i++)
	{
		while(!q.empty()&&q.front()<i-k) q.pop_front();
		f[i]=max(f[i-1],xiaolv(q.front())+s[i]);
		while(!q.empty()&&xiaolv(q.back())<=xiaolv(i)) q.pop_back();
		q.push_back(i);
	 } 
	 cout<<f[n];
	return 0;
}
