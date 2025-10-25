#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5,M=2e6+5;
ll head[N],cnt,n,m;
struct Edge{
	ll from,to,next;
	ll w;
};
Edge edge[M];
void addedge(ll u,ll v,ll w)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	for(ll i=head[2];i>0;i=edge[i].next) cout<<edge[i].to<<"  ";
	return 0;
}
