#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c[20],n,w,a[20],ans=0x3f3f3f3f;
bool cmp(ll a,ll b)
{
	return a>b;
}
void dfs(ll step,ll sum)
{
	ll x=c[step];
	if(step>=n+1)
	{
		ans=min(ans,sum);
		return;
	}
	if(sum>ans) return;
	for(ll i=1;i<=sum;i++)
	{
		if(x+a[i]<=w)
		{
			a[i]=a[i]+x;
			dfs(step+1,sum);
			a[i]=a[i]-x;
		}
	}
	a[sum+1]=x;
	dfs(step+1,sum+1);
	a[sum+1]=0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>w;
	for(ll i=1;i<=n;i++)  cin>>c[i];
	sort(c+1,c+n+1,cmp);
	dfs(1,1);
	cout<<ans;
	return 0;
}
