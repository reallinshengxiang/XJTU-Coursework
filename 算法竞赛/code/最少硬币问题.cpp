#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
struct yinbi{
	ll t,coins;
};
yinbi a[N];
ll c[N],n,m;
bool cmp(yinbi x,yinbi y)
{
	if(x.t>y.t) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(c,127,sizeof(c)); 
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].t>>a[i].coins;
	cin>>m;
	sort(a+1,a+n+1,cmp);
	c[0]=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll k=1;k<=a[i].t;k++)
		{
			for(ll j=m;j>=a[i].t;j--) c[j]=min(c[j],c[j-a[i].t]+1);
		}
	}
	cout<<c[m];
	return 0;
}
