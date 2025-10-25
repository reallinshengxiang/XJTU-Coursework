#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10,mod=1e9+9;
ll a[N],ans=1,n,k,x,y,flag=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(k%2)
	{
		ans=a[n]%mod;
		n--;
		k--;
		if(ans<0) flag=-1;
	}
	ll l=1,r=n;
	while(k)
	{
		k=k-2;
		x=a[l]*a[l+1];
		y=a[r]*a[r-1];
		if(x*flag>y*flag) ans=(ans*(x%mod))%mod,l=l+2;
		else ans=(ans*(y%mod))%mod,r=r-2;
	}
	cout<<ans;
	return 0;
}
