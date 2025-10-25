#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct edge{
	ll u,v,w;
};
edge e[N];
ll ans,s[N],n,m;
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
ll find_set(ll x)
{
	if(x!=s[x]) s[x]=find_set(s[x]);
	return s[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) s[i]=i;
	for(ll i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(ll i=1;i<=m;i++)
	{
		ll x=find_set(e[i].u);
		ll y=find_set(e[i].v);
		if(x!=y)
		{
			ans=ans+e[i].w;
			s[x]=y;
		}
	}
	cout<<ans;
	return 0;
}
