#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
vector<ll> edge[N];
queue<ll> st;
ll n,m;
void dfs(ll x)
{
	for(ll i=0;i<edge[x].size();i++)
	{
		ll y=edge[x][i];
		if(y)
		{
			edge[x][i]=0;
			dfs(y);
		}
	}
	st.push(x);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	while(m--)
	{
		ll u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1);
	while(!st.empty())
	{
		cout<<st.front()<<"\n";
		st.pop();
	}
	return 0;
}
