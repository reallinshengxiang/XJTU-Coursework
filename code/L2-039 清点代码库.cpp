#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
struct sz{
	ll num,m;
	vector<ll> x;
	bool operator< (sz xx) const
	{
		if(num>xx.num) return 1;
		if(num<xx.num) return 0;
		for(ll i=1;i<=m;i++)
		{
			if(x[i]<xx.x[i]) return 1;
			if(x[i]>xx.x[i]) return 0;
		}
		return 1;
	}
};
ll n,m;
sz a[N];
bool check(sz x,sz y)
{
	for(ll i=1;i<=m;i++)
	{
		if(x.x[i]!=y.x[i]) return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		a[i].m=m;
		ll xx;
		a[i].x.push_back(0);
		for(ll j=1;j<=m;j++) 
		{
			cin>>xx;
			a[i].x.push_back(xx);
		}
	}
	sort(a+1,a+n+1);
	ll cnt=1;
	ll last=1;
	for(ll i=1;i<=n;i++)
	{
		if(check(a[i],a[last])) a[last].num++;
		else 
		{
			cnt++;
			last=i;
			a[i].num++;
		}		
	}
	sort(a+1,a+n+1);
	cout<<cnt<<"\n";
	for(ll i=1;i<=n;i++)
	{
		if(a[i].num>0) cout<<a[i].num<<" ";
		else break;
		for(ll j=1;j<=m-1;j++) cout<<a[i].x[j]<<" ";
		cout<<a[i].x[m]<<"\n";
	}
	return 0;
}
