#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll a[N],cnt,x,n;
map<ll,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],mp[a[i]]++;
	for(ll i=1;i<=n;i++)
	{
		if(cnt==0)
		{
			x=a[i];
			cnt++;
		}
		else
		{
			if(x==a[i]) cnt++;
			else cnt--;
		}
	}
	if(mp[x]>=n/2+1) cout<<"YES "<<x;
	else cout<<"NO";
	return 0; 
} 


