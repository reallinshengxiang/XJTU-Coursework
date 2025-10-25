#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll a[N],r[N],d[N],s[N],t[N],ans,n,m;
ll check(ll x)
{
	ll sum=0;
	memset(a,0,sizeof(a));
	for(ll i=1;i<=x;i++)
	{
		a[s[i]]=a[s[i]]+d[i];
		a[t[i]+1]=a[t[i]+1]-d[i];
	}
	for(ll i=1;i<=n;i++)
	{		
		sum=sum+a[i];
		if(sum>r[i]) return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>r[i];
	for(ll i=1;i<=m;i++) cin>>d[i]>>s[i]>>t[i];
	ll mid,l=0,r=m;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	if(ans>=m) cout<<"0";
	else cout<<"-1\n"<<ans+1;
	return 0;
}
