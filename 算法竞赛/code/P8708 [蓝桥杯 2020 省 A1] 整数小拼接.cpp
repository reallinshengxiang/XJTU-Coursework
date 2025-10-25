#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,k,a[N],ans;
ll merge(ll x1,ll x2)
{
	return stoll(to_string(x1)+to_string(x2));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll pos=n;
	for(ll i=1;i<=n;i++)
	{
		while(merge(a[i],a[pos])>k&&pos>=1) pos--;
		ans=ans+pos;
		if(pos>=i) ans--;
		if(pos==0) break;
	}
	cout<<ans;
	return 0;
} 
