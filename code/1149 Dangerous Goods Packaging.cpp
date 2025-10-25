#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e4+10;
ll n,m,k,flag,a[N],x[N],y[N];
map<ll,ll> vis;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>x[i]>>y[i];
	while(m--)
	{
		cin>>k;
		vis.clear();
		flag=1;
		for(ll i=1;i<=k;i++) cin>>a[i],vis[a[i]]=1;
		for(ll i=1;i<=n;i++)
		{
			if(vis[x[i]]&&vis[y[i]])
			{
				flag=0;
				break;
			}
		}
		if(!flag) cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}
