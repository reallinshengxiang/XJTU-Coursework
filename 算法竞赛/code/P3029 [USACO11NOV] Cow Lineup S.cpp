#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e4+10;
struct cow{
	ll x,id;
};
cow a[N];
ll n,id,cnt,num[N],sum,ans=1e9;
unordered_map<ll,ll> mp;
deque<ll> q;
bool cmp(cow a,cow b)
{
	if(a.x<b.x) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].x>>id;
		if(!mp[id]) cnt++,mp[id]=cnt;
		a[i].id=mp[id];
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++)
	{
		if(num[a[i].id]==0)	sum++;	
		num[a[i].id]++;
		q.push_back(i);
		while(num[a[q.front()].id]>=2&&!q.empty())
		{
			num[a[q.front()].id]--;
			q.pop_front();
		}
		if(sum==cnt) ans=min(ans,a[q.back()].x-a[q.front()].x);
	}
	cout<<ans;
	return 0;
}
