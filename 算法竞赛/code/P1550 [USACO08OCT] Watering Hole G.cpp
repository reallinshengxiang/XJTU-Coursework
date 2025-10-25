#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=4e5+10;
struct Edge{
	ll u,v,w;
};
Edge edge[N];
bool cmp(Edge a,Edge b){return a.w<b.w;}
ll n,m,s[N],k,w[N];
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
		ll e1=find_set(edge[i].u);
		ll e2=find_set(edge[i].v);
		if(e1==e2) continue;
		ans=ans+edge[i].w;
		s[e1]=e2;
		cnt++;
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>w[i];
	for(ll i=1;i<=n;i++)  
	{
		for(ll j=1;j<=n;j++)
		{
			ll p;
			cin>>p;
			m++;
			edge[m].u=i;
			edge[m].v=j;
			edge[m].w=p;
		}
	}
	for(ll i=1;i<=n;i++) 
	{
		m++;
		edge[m].u=0;
		edge[m].v=i;
		edge[m].w=w[i];
	}
	kruskal();	
	return 0;
}
