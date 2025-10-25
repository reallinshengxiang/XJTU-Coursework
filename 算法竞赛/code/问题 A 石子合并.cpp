#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=0x7fffffff;
ll n,m,ans1,ans2,a[205],f1[205][205],f2[205][205];;
ll dfs1(ll l,ll r)
{
	if(f1[l][r]) return f1[l][r];
	if(l==r)
	{
		f1[l][r]=0;
		return 0;
	}
	ll ans=INF;
	for(ll i=l; i<=r-1; i++)  ans=min(ans,dfs1(l,i)+dfs1(i+1,r)+a[r]-a[l-1]);
	f1[l][r]=ans;
	return ans;
}
ll dfs2(ll l,ll r)
{
	if(f2[l][r])  return f2[l][r];
	if(l==r)
	{
		f2[l][r]=0;
		return 0;
	}
	ll ans=0;
	for(ll i=l; i<=r-1; i++)   ans=max(ans,dfs2(l,i)+dfs2(i+1,r)+a[r]-a[l-1]);
	f2[l][r]=ans;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1; i<=n; i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int i=1; i<=2*n; i++)   a[i]=a[i]+a[i-1];
	dfs1(1,2*n);
	dfs2(1,2*n);
	ans1=INF;
	ans2=0;
	for(int i=1; i<=n; i++)
	{
		ans1=min(f1[i][n+i-1],ans1);
		ans2=max(f2[i][n+i-1],ans2);
	}
	cout<<ans1<<"\n"<<ans2;
	return 0;
}
