#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+2000;
ll n,m,f[N],degree[N],flag[N],cut[N],sum,ans,cnt;
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void merge(ll x,ll y)
{
	if(find_set(x)!=find_set(y)) f[find_set(x)]=find_set(y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=2*m+n;i++) f[i]=i;
	for(ll i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		if(x==0)
		{
			n++;
			x=n;
		}
		if(y==0)
		{
			n++;
			y=n;
		}
		degree[x]++;
		degree[y]++;
		merge(x,y);
	}
	for(ll i=1;i<=n;i++)
	{
		if(f[i]==i&&degree[i]) cnt++;
	}
	if(cnt==1)
	{
		for(ll i=1;i<=n;i++)
		{
			if(degree[i])
			{
				if(degree[i]%2) sum++;
				if(degree[i]>2) ans++;
			}
		}
	}
	else
	{
		for(ll i=1;i<=n;i++)
		{
			if(degree[i])
			{
				if(degree[i]%2) 
				{
					sum++;
					cut[find_set(i)]=1;
				}
			    if(degree[i]>2) 
				{
					ans++;
					flag[find_set(i)]=1;
				}
			}
		}
		for(ll i=1;i<=n;i++)
		{
			if(f[i]==i&&degree[i]&&!cut[i]) 
			{
				ans++;
				if(!flag[i]) ans++;
			}
		}
	}
	cout<<(ans+sum/2);
	return 0;
}
