#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct sp{
	ll p,q,r;
};
sp a[N];
struct question{
	ll k,v,id;
};
question b[N];
ll ans[N],n,q,m,f[N],sum[N];
bool cmp1(sp a,sp b)
{
	if(a.r>b.r) return 1;
	return 0;
}
bool cmp2(question a,question b)
{
	if(a.k>b.k) return 1;
	return 0;
}
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	if(x==y) return;
	f[y]=x;
	sum[x]=sum[x]+sum[y];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++)
	{
		f[i]=i;
		sum[i]=1;
	}
	for(ll i=1;i<=n-1;i++) cin>>a[i].p>>a[i].q>>a[i].r;
	for(ll i=1;i<=q;i++)
	{
		cin>>b[i].k>>b[i].v;
		b[i].id=i;
	}
	sort(a+1,a+n,cmp1);
	sort(b+1,b+q+1,cmp2);
	ll j=1;
	for(ll i=1;i<=q;i++)
	{
		while(j<=n&&b[i].k<=a[j].r)
		{
			merge(a[j].p,a[j].q);
			j++;
		}
		ans[b[i].id]=sum[find_set(b[i].v)]-1;
	}
	for(ll i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}
