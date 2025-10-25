#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	ll x,y;
};
point p[1010];
vector<ll> st;
ll a[1010][1010],c,n;
ll get(ll x)
{
	return lower_bound(st.begin(),st.end(),x)-st.begin();
}
bool check(ll len)
{
	ll x1=0;
	for(ll x2=1;x2<st.size();x2++)
	{
		while(st[x2]+1-st[x1+1]>len) x1++;
		ll y1=0;
		for(ll y2=1;y2<st.size();y2++)
		{
			while(st[y2]+1-st[y1+1]>len) y1++;
			if(a[x2][y2]-a[x1][y2]-a[x2][y1]+a[x1][y1]>=c) return 1;
	    }
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n;
	st.push_back(0);
	for(ll i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
		st.push_back(p[i].x);
		st.push_back(p[i].y);
	}
	sort(st.begin(),st.end());
	st.erase(unique(st.begin(), st.end()), st.end());
	for(ll i=1;i<=n;i++)
	{
		ll x=get(p[i].x);
		ll y=get(p[i].y);
		a[x][y]++;
	}
	for(ll i=1;i<st.size();i++)
	{
		for(ll j=1;j<st.size();j++) a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	}
	ll l=1,r=10000;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<r+1;
	return 0;
}
