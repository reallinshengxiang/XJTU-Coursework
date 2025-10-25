#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e6+10;
struct edge{
	ll from,to,w;
};
edge e[N];
ll f[N],cnt,ans,num;
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void kruskal()
{
	for(ll i=1;i<=2021;i++) f[i]=i;
	for(ll i=1;i<=cnt;i++)
	{
		ll x=find_set(e[i].from);
		ll y=find_set(e[i].to);
		if(x==y) continue;
		f[x]=y;
		ans=ans+e[i].w;
		num++;
		if(num==2020)
		{
			cout<<ans;
			exit(0);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=2021;i++)
	{
		for(ll j=i+1;j<=2021;j++)
		{
			ll x=i;
			ll y=j;
			ll w=0;
			for(ll k=1;k<=4;k++)
			{
				if(x%10!=y%10) w=w+x%10+y%10;
				x=x/10;
				y=y/10;
			}
			e[++cnt].from=i;
			e[cnt].to=j;
			e[cnt].w=w;
			e[++cnt].from=j;
			e[cnt].to=i;
			e[cnt].w=w;
		}
	}
	sort(e+1,e+cnt+1,cmp);
	kruskal();
	return 0;
}
