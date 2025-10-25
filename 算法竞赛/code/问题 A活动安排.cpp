#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct hd{
	ll s,f;
};
hd a[1010];
ll ans,t,n;
bool cmp(hd a,hd b)
{
	return a.f<b.f;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)  cin>>a[i].s>>a[i].f;
	sort(a+1,a+n+1,cmp);
    t=0;
    ans=0;
	for(ll i=1;i<=n;i++)
	{
		if(a[i].s>=t)
		{
			ans++;
			t=a[i].f;
		}
	}
	cout<<ans;
	return 0;
}
