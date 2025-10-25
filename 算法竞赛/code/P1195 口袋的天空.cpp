#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct Edge{
	ll u,v,w;
};
Edge edge[N];
bool cmp(Edge a,Edge b){return a.w<b.w;}
ll n,m,s[N],k;
ll find_set(ll x)
{
	if(x!=s[x]) s[x]=find_set(s[x]);
	return s[x];
}
void kruskal()
{
	sort(edge+1,edge+m+1,cmp);
	for(ll i=1;i<=n;i++) s[i]=i;
	ll ans=0,cnt=0;
	for(ll i=1;i<=m;i++)
	{
		if(cnt==n-k) break;
		ll e1=find_set(edge[i].u);
		ll e2=find_set(edge[i].v);
		if(e1==e2) continue;
		ans=ans+edge[i].w;
		s[e1]=e2;
		cnt++;
	}
	if(cnt==n-k) cout<<ans;
	else cout<<"No Answer";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)  cin>>edge[i].u>>edge[i].v>>edge[i].w;
	kruskal();	
	return 0;
}
