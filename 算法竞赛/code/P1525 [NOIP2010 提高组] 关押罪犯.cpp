#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
struct qf{
	ll x,y,c;
}; 
qf a[N];
bool cmp(qf a,qf b)
{
	if(a.c>b.c) return 1;
	return 0;
}
ll f[N],n,m,e[N];
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	f[x]=y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].c;
	for(ll i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=m+1;i++)
	{
		if(find_set(a[i].x)==find_set(a[i].y))
		{
			cout<<a[i].c;
			return 0;
		}
		else
		{
			if(!e[a[i].x]) e[a[i].x]=a[i].y;
			else merge(e[a[i].x],a[i].y);
			if(!e[a[i].y]) e[a[i].y]=a[i].x;
			else merge(e[a[i].y],a[i].x);
		}
	} 
	return 0;
} 
