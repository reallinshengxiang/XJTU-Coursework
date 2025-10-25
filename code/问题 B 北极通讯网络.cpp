#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Edge{
	ll x,y;
	double dis;
};
Edge edge[250010];
ll n,k,x[550],y[550],f[550],cnt;
double d;
bool cmp(Edge a,Edge b)
{
	return a.dis<b.dis;
}
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
double kruskal()
{
	sort(edge+1,edge+cnt+1,cmp);
	for(ll i=1;i<=n;i++) f[i]=i;
	ll mm=0;
	for(ll i=1;i<=cnt;i++)
	{
		ll e1=find_set(edge[i].x);
		ll e2=find_set(edge[i].y);
		if(e1==e2) continue;
		else
		{
			f[e1]=e2;
			mm++;
			if(mm==n-k)
			{
				d=edge[i].dis;
				return d;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>x[i]>>y[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+1;j<=n;j++) 
		{
			cnt++;
			edge[cnt].x=i;
			edge[cnt].y=j;
			edge[cnt].dis=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
	}
    cout<<fixed<<setprecision(2)<<kruskal();	
	return 0;
}
