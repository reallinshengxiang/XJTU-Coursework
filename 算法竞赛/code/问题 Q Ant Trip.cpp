#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll f[N],root[N],d[N],sum,ans,n,m;
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	if(x!=y) f[y]=x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m)
	{
		for(ll i=1;i<=n;i++) f[i]=i;
		memset(root,0,sizeof(root));
		memset(d,0,sizeof(d));
		for(ll i=1;i<=m;i++)
		{
			ll a,b;
			cin>>a>>b;
			merge(a,b);
			d[a]++;
			d[b]++;
		}
		sum=0;
		ans=0;
		for(ll i=1;i<=n;i++)
		{
			if(d[i]%2)
			{
				root[find_set(i)]=1;
				sum++;
			}
		}
		for(ll i=1;i<=n;i++)
		{
			if(!root[i]&&d[i]&&f[i]==i) ans++;
		}
		cout<<(sum/2+ans)<<"\n";
	}
	return 0;
}
