#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10,M=2e5+10;
struct Edge{
	ll u,v,w;
};
Edge edge[M];
bool cmp(Edge a,Edge b){return a.w<b.w;}
ll f[N],n,m;
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x]; 
}
void kruskal()
{
	sort(edge+1,edge+m+1,cmp);
	for(ll i=1;i<=n;i++) f[i]=i;
	ll ans=0,cnt=0;
	for(ll i=1;i<=m;i++)
	{
		if(cnt==n-1) break;
		ll e1=find_set(edge[i].u);
		ll e2=find_set(edge[i].v);
		if(e1==e2) continue;
		else
		{
			ans=ans+edge[i].w;
			f[e1]=e2;
			cnt++;
		}
	}
	if(cnt==n-1) cout<<ans;
	else cout<<"impossible";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	kruskal();
	return 0;
}
