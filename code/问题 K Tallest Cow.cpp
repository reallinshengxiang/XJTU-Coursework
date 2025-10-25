#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<ll,ll>,ll> mp;
ll x,y,n,m,p,h,a[10010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>p>>h>>m;
	while(m--)
	{
		cin>>x>>y;
		if(x>y) swap(x,y);
		if(mp[make_pair(x,y)]) continue;
		a[y]++;
		a[x+1]--;
		mp[make_pair(x,y)]=1;
	}
	for(ll i=1;i<=n;i++)
	{
		a[i]=a[i]+a[i-1];
		cout<<h+a[i]<<"\n";
	} 
	return 0;
}
