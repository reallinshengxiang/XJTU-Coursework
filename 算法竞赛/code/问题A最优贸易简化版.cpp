#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,p[100010],mi[100010],ma[100010],v[100010],nn;
ll dfs(ll l,ll r)
{
	ll minn=p[l],s1=l/nn,s2=r/nn,ans=0;
	if(s1==s2) 
	{
		for(ll i=l;i<=r;i++)
		{
			ans=max(ans,p[i]-minn);
			minn=min(minn,p[i]);			
		}
	}
	else
	{
		for(ll i=l;i<=nn*(s1+1)-1;i++)
		{			
			ans=max(ans,p[i]-minn);
			minn=min(minn,p[i]);
		}
		for(ll i=s1+1;i<=s2-1;i++)
		{
			ans=max(v[i],max(ans,ma[i]-minn));
			minn=min(minn,mi[i]);
		}
		for(ll i=nn*s2;i<=r;i++)
		{			
			ans=max(ans,p[i]-minn);
			minn=min(minn,p[i]);
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(mi,127,sizeof(mi));
	cin>>n>>m;
	nn=sqrt(n);
	for(ll i=1;i<=n;i++) cin>>p[i];
	for(ll i=1;i<=n;i++)
	{
		ll t=i/nn;
		mi[t]=min(mi[t],p[i]);
		v[t]=max(v[t],p[i]-mi[t]);
		ma[t]=max(ma[t],p[i]);
	}
	for(ll i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		cout<<dfs(x,y)<<"\n";
	}
	return 0;
} 
