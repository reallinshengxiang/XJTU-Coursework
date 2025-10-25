#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
const ll N=1e5+10;
struct star{
	ll a,b;
};
star s[N];
ll n,l,r,c;
ll check(ll x)
{
	ll nx=0;
	for(ll i=1;i<=n;i++) 
	{
		if(s[i].b>r) continue;
		nx=nx+(x-s[i].b)/s[i].a+1;
		if(s[i].b<l) nx=nx-(l-1-s[i].b)/s[i].a-1;
		if(nx>=c) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>s[i].a;
	for(ll i=1;i<=n;i++) cin>>s[i].b;
	cin>>l>>r>>c;
	ll num=0;
	for(ll i=1;i<=n;i++) 
	{
		if(s[i].b>r) continue;
		num=num+(r-s[i].b)/s[i].a+1;
		if(s[i].b<l) num=num-(l-1-s[i].b)/s[i].a-1;
	}
	//cout<<num<<"\n";
	if(num<c)
	{
		cout<<"-1";
		return 0;
	}
	ll pl=l,pr=r,mid,ans=r;
	while(pl<=pr)
	{
		mid=(pl+pr)/2;
		if(check(mid)) pr=mid-1,ans=mid;
		else pl=mid+1; 
	}
	cout<<ans;
	return 0;
} 
