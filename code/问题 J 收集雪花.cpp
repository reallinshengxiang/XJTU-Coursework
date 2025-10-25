#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
unordered_map<ll,ll> mp;
ll ans,n,a[N],l,r;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	l=r=1;
	while(r<=n)
	{
		mp[a[r]]++;
		while(mp[a[r]]>=2)
		{
			mp[a[l]]--;
			l++;
		}
		ans=max(r-l+1,ans); 
		r++; 
	}
	cout<<ans;
	return 0;
}
