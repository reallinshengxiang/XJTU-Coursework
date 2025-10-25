#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#pragma GCC optimize(2)
const ll N=1e5+10;
struct sb{
	ll p,c;
};
sb a[N];
ll ans,n,s,sum[N];
bool cmp(sb x,sb y)
{
	if(x.c<=y.c) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s;
	for(ll i=1;i<=n;i++) 	cin>>a[i].p>>a[i].c;
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].p;
	ll yl=0;
	for(ll i=1;i<=n;i++)
	{
		if(a[i].c==yl) continue;
		ans=ans+(a[i].c-yl)*min(s,sum[n]-sum[i-1]);
		yl=a[i].c;
	}
	cout<<ans;
	return 0;
}
