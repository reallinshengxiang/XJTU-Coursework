#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll T,n,a[N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i];
		map<ll,ll> mp;
		deque<ll> q;
		ans=0;
		for(ll i=1;i<=n;i++)
		{
			mp[a[i]]++;
			while(!q.empty()&&mp[a[i]]>=2) mp[a[q.front()]]--,q.pop_front();
			q.push_back(i);
			ans=max(ans,q.back()-q.front()+1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
