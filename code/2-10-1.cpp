#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll a[N],ans,n;
map<ll,ll> mp;
ll search(ll l,ll r)
{
	if(l==r) return a[l];
	ll mid=(l+r)/2;
	ll x=search(l,mid);
	ll y=search(mid+1,r);
	if(x==y) return x;                    
	else if(x!=-1&&y!=-1)
	{
		if(mp[x]>=n/2+1) return x;
		else if(mp[y]>=n/2+1) return y;
		else return -1;
	}
	else if(x!=-1)
	{
		if(mp[x]>=n/2+1) return x;
		else return -1;
	}
	else if(y!=-1)
	{
		if(mp[y]>=n/2+1) return y;
		else return -1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],mp[a[i]]++;
	ans=search(1,n);
	if(ans==-1) cout<<"NO";
	else cout<<"YES "<<ans;
	return 0; 
} 


