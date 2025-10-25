#include<bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<pair<long long,long long>> heap;
ll maxx,f[110],d[110],t[110],n,h,ans,tim,tt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>h;
	tim=h*60;
	for(ll i=1;i<=n;i++)  cin>>f[i];
	for(ll i=1;i<=n;i++)  cin>>d[i];
	t[1]=0;
	for(ll i=2;i<=n;i++)  
	{
		cin>>t[i];
		t[i]=t[i]+t[i-1];
	}
	for(ll i=1;i<=n;i++)
	{
		tt=tim-5*t[i];
		ans=0;
		for(ll j=1;j<=i;j++) heap.push(make_pair(f[j],j));
		while(tt>0&&heap.top().first>0)
		{
			pair<long long,long long> a;
			a=heap.top();
			heap.pop();
			ans=ans+a.first;
			a.first=a.first-d[a.second];
			heap.push(a);
			tt=tt-5;
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
