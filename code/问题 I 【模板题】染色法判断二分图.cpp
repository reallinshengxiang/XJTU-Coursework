#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
struct Edge{
	ll to,next;
};
Edge edge[N];
ll cnt,head[N],color[N],flag,n,m;
void add_edge(ll from,ll to)
{
	cnt++;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
ll dfs(ll x,ll c)
{
	color[x]=c;
	for(ll i=head[x];~i;i=edge[i].next)
	{
		ll to=edge[i].to;
		if(color[to]==c) return 0;
		else if(color[to]==-1)
		{
			if(!dfs(to,(!c))) return 0;
		}
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) head[i]=color[i]=-1;
	for(ll i=1;i<=2*m;i++) edge[i].next=-1;
	for(ll i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		add_edge(x,y);
		add_edge(y,x);
	}
	flag=1;
	for(ll i=1;i<=n;i++)
	{
		if(color[i]==-1)
		{
			if(dfs(i,0)==0)
			{
				flag=0;
				break;
			}
		}
	}
	if(flag) cout<<"Yes";
	else cout<<"No";
	return 0;
}
