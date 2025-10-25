#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,d,ans;
vector<ll> e[N];
map<ll,ll> mp;
void dfs(ll x,ll step)
{
	mp[x]=1;
	if(step>=d) return;
	for(ll i=0;i<e[x].size();i++)
	{
		ll y=e[x][i];
		if(mp[y]) continue;
		ans++;
		dfs(y,step+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>d;
	for(ll i=1;i<=n-1;i++)
	{
		ll u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	} 
	dfs(1,0);
	cout<<ans;
	return 0;
}
