#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=5005,M=2e5+1;
struct Edge
{
	ll u,v,w;
} edge[M];     
bool cmp(Edge a, Edge b)
{
	return a.w<b.w; 
}
ll s[N];                             
ll find_set(ll x)                
{
	if(x!=s[x])  s[x]=find_set(s[x]);        
	return s[x];
}
ll n,m;                           
void kruskal()
{
	sort(edge+1, edge+m+1, cmp);     
	for(ll i=1;i<=n;i++) s[i]=i;   
	ll ans=0,cnt=0;              
	for(ll i=1;i<=m;i++)          
	{
		if(cnt == n-1)    break;      
		ll e1=find_set(edge[i].u); 
		ll e2=find_set(edge[i].v); 
		if(e1==e2) continue;        
		else                          
		{
			ans+=edge[i].w;        
			s[e1]= e2;               
			cnt++;                   
		}
	}
	if(cnt==n-1) cout<<ans;      
	else cout<<"No Answer!";             
}
int main()
{
	cin>>n>>m;
	for(ll i=1;i<=m;i++)  cin>>edge[i].u>>edge[i].v>>edge[i].w;
	kruskal();
	return 0;
}


