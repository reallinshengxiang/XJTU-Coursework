#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct way{
	ll x,y,t;
};
way a[N];
bool cmp(way a,way b)
{
	if(a.t<b.t) return 1;
	return 0;
}
ll f[N],n,m,sum;
ll find_set(ll x)
{
	if(f[x]!=x) f[x]=find_set(f[x]);
	return f[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) f[i]=i;
	for(ll i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].t;
	sort(a+1,a+m+1,cmp);
	sum=n;
	for(ll i=1;i<=m;i++)
	{
		if(find_set(a[i].x)!=find_set(a[i].y))
		{
			sum--;
			f[find_set(a[i].x)]=find_set(a[i].y);
		}
		if(sum==1)
		{
			cout<<a[i].t;
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}
