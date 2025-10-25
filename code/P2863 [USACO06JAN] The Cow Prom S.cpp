#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll cnt,dfn,low[N],num[N],sccno[N],sum[N],ans,n,m;
vector<ll> edge[N];
stack<ll> st;
void dfs(ll u)
{
	st.push(u);
	dfn++;
	low[u]=num[u]=dfn;
	for(ll i=0;i<edge[u].size();i++)
	{
		ll v=edge[u][i];
		if(!num[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!sccno[v])  low[u]=min(low[u],num[v]);
	}
	if(low[u]==num[u])
	{
		cnt++;
		while(1)
		{
			ll v=st.top();
			st.pop();
			sccno[v]=cnt;
			if(u==v) break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll a,b;
		cin>>a>>b;
		edge[a].push_back(b);
	}
	for(ll i=1;i<=n;i++)
	{
		if(!num[i]) dfs(i);
	}
	for(ll i=1;i<=n;i++) sum[sccno[i]]++;
	for(ll i=1;i<=cnt;i++) 
	{
		if(sum[i]>1) ans++;
	}
	cout<<ans;
	return 0;
} 
