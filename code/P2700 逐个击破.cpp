#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct Edge{
	ll u,v,w;
};
Edge edge[N];
bool cmp(Edge a,Edge b){return a.w>b.w;}
ll n,m,s[N],k,ans,sum,city[N];
ll find_set(ll x)
{
	if(x!=s[x]) s[x]=find_set(s[x]);
	return s[x];
}
void kruskal()
{
	sort(edge+1,edge+n,cmp);
	for(ll i=0;i<=n;i++) s[i]=i;
	for(ll i=1;i<=n-1;i++)
	{
		ll e1=find_set(edge[i].u);
		ll e2=find_set(edge[i].v);
		if(city[e1]&&city[e2]) continue;
		s[e1]=e2;
		if(city[e1]) city[e2]=1;
		ans=ans+edge[i].w;		
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=k;i++) 
	{
		ll x;
		cin>>x;
		city[x]=1;
	}
	for(ll i=1;i<=n-1;i++)  
	{
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		sum=sum+edge[i].w;
	}
	kruskal();
	cout<<sum-ans;	
	return 0;
}
