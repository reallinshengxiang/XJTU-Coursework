#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll f[N],dis[N],n,m,x,maxdis,sum;
ll dfs(ll x,ll step)
{
	if(f[x]==-1||dis[x])
	{
		maxdis=max(maxdis,dis[x]+step);
		return step*2;
	}
	ll ans=dfs(f[x],step+1);
	dis[x]=dis[f[x]]+1;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>f[i];
	while(m--)
	{
		ll x;
		cin>>x;
		sum=sum+dfs(x,0);
		cout<<sum-maxdis<<"\n";
	}
	return 0;
}
