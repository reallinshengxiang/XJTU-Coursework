#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=4e5+10;
ll f[N],flag[N],a[N],ans[N],sum,n,m,k;
vector<ll> e[N];
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	f[y]=x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) f[i]=i;
	for(ll i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	cin>>k;
	for(ll i=1;i<=k;i++)
	{
		cin>>a[i];
		flag[a[i]]=1;
	}
	sum=n-k;
	for(ll i=0;i<=n-1;i++)
	{
		for(ll j=0;j<e[i].size();j++)
		{
			if(!flag[i]&&!flag[e[i][j]])
			{
				if(find_set(i)!=find_set(e[i][j]))
				{
					sum--;
					merge(i,e[i][j]);
				}
			}
		}
	}
	ans[k+1]=sum;
	for(ll i=k;i>=1;i--)
	{
		sum++;
		flag[a[i]]=0;
		for(ll j=0;j<e[a[i]].size();j++)
		{
			if(!flag[e[a[i]][j]]&&find_set(a[i])!=find_set(e[a[i]][j]))
			{
				sum--;
				merge(a[i],e[a[i]][j]);
			}
		}
		ans[i]=sum;
	}
	for(ll i=1;i<=k+1;i++) cout<<ans[i]<<"\n";
	return 0;
}
