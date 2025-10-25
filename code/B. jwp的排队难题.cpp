#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct men{
	ll bz,tim;
};
men a[100010];
bool cmp(men xx,men yy)
{
	return (xx.bz*yy.tim)>(xx.tim*yy.bz);
}
ll ans,t,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].bz>>a[i].tim;
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++)
	{
		t=t+a[i].tim;
		ans=ans+t*a[i].bz;
	}
	cout<<ans;
	return 0;
}
