#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
vector<ll> e[N];
ll x,y,k,n,m,ans,a[N],vis[N],num[N];
void dfs(ll x)
{
	vis[x]=1;
	num[x]++;
	for(ll i=0;i<e[x].size();i++)
	{
		if(!vis[e[x][i]]) dfs(e[x][i]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k>>n>>m;
	for(ll i=1;i<=k;i++) cin>>a[i];
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y;
		e[x].push_back(y);
	}
	for(ll i=1;i<=k;i++)
	{
	    dfs(a[i]);
		memset(vis,0,sizeof(vis));		
	}
	for(ll i=1;i<=n;i++)
	{
		if(num[i]==k) ans++;
	}
	cout<<ans;
	return 0;
} 
