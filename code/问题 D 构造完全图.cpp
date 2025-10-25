#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct Edge{
	ll x,y,dis;
};
Edge edge[N];
ll f[N],ans,sum[N],n;
bool cmp(Edge x,Edge y)
{
	return x.dis<y.dis;
}
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void kruskal()
{
	sort(edge+1,edge+n,cmp);
	for(ll i=1;i<=n;i++) 
	{
		f[i]=i;
		sum[i]=1;
	}
	for(ll i=1;i<=n-1;i++)
	{
		ll e1=find_set(edge[i].x);
		ll e2=find_set(edge[i].y);
		if(e1!=e2)
		{
			ans=ans+(edge[i].dis+1)*(sum[e1]*sum[e2]-1);
			f[e1]=e2;
			sum[e2]=sum[e2]+sum[e1];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n-1;i++)	
	{
		cin>>edge[i].x>>edge[i].y>>edge[i].dis;
		ans=ans+edge[i].dis;
	}
	kruskal();
	cout<<ans;	
	return 0;
}
