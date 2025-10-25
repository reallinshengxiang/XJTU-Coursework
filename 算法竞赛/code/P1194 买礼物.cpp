#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+10;
struct Edge{
	ll u,v,w;
};
Edge edge[N];
bool cmp(Edge a,Edge b){return a.w<b.w;}
ll a,b,w,m,s[N],k;
ll find_set(ll x)
{
	if(x!=s[x]) s[x]=find_set(s[x]);
	return s[x];
}
void kruskal()
{
	sort(edge+1,edge+m+1,cmp);
	for(ll i=1;i<=b;i++) s[i]=i;
	ll ans=0,cnt=0;
	for(ll i=1;i<=m;i++)
	{
		if(cnt==b) break;
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
	cin>>a>>b;
	for(ll i=1;i<=b;i++)  
	{
		for(ll j=1;j<=b;j++)
		{
			cin>>w;
			if(w==0) w=a;
			m++;
			edge[m].u=i;
			edge[m].v=j;
			edge[m].w=min(w,a);
		}
	}
	for(ll i=1;i<=b;i++) 
	{
		m++;
		edge[m].u=0;
		edge[m].v=i;
		edge[m].w=a;
	}
	
	kruskal();	
	return 0;
}
