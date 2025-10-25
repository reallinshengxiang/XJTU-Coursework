#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,n,c,a[1010],sum[1010];
void dfs(ll step,ll s)
{
	if(s+sum[step]<=ans) return;
	ans=max(ans,s);
	for(ll i=step;i>=0;i--)
	{
		if(s+a[i]<=c) dfs(i-1,s+a[i]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>c;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
    for(ll i=1;i<=n;i++)
    {
    	if(a[i]>c)
    	{
    		n=i-1;
    		break;
		}
	}
	dfs(n,0);
	cout<<ans;
	return 0;
}
