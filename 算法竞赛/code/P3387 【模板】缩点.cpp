#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
stack<ll> st;
ll n,m,cnt,dfn,a[N],low[N],sccno[N],num[N],sum[N],ans;
vector<ll> edge[N];
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
			low[u]=min(low[v],low[u]);
		}
		else if(!sccno[v]) low[u]=min(low[u],num[v]);
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
void tarjan(ll n)
{
	cnt=dfn=0;
	memset(sccno,0,sizeof(sccno));
	memset(num,0,sizeof(num));
	memset(low,0,sizeof(low));
	for(ll i=1;i<=n;i++)
	{
		if(!num[i]) dfs(i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		edge[u].push_back(v);
	}
	tarjan(n);
	for(ll i=1;i<=n;i++)
	{
		cout<<i<<"  "<<sccno[i]<<"\n";
		sum[sccno[i]]=sum[sccno[i]]+a[i];
		ans=max(ans,sum[sccno[i]]);
	}
	cout<<ans;
	return 0;
}
