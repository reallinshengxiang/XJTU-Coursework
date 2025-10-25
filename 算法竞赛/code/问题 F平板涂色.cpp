#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll xa,xb,ya,yb,color;
};
node a[30];
vector<ll> g[30];
ll ans,n,vis[30];
ll check(ll x)
{
	for(ll i=0;i<g[x].size();i++)
	{
		if(!vis[g[x][i]]) return 0;
	}
	return 1;
}
void dfs(ll sum,ll step,ll last)
{
	if(sum>=ans) return;
	if(step==n) 
	{
		ans=min(ans,sum);
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i]&&(check(i)||!a[i].xa))
		{
			vis[i]=1;
			dfs(sum+(a[i].color!=last),step+1,a[i].color);
			vis[i]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].xa>>a[i].ya>>a[i].xb>>a[i].yb>>a[i].color;
	ll m=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(i!=j) 
			{
				if(a[i].xa==a[j].xb&&!(a[j].yb<a[i].ya||a[j].ya>a[i].yb)) g[i].push_back(j);
			}
		}
	}
	ans=0x7f;
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
