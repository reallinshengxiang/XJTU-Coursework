#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e4+10;
ll n,m,x[N],y[N],nv,vis[N],k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++) cin>>x[i]>>y[i];
	cin>>k;
	while(k--)
	{
		cin>>nv;
		for(ll i=0;i<=n-1;i++) vis[i]=0;
		for(ll i=1;i<=nv;i++) 
		{
			ll xx;
			cin>>xx;
			vis[xx]=1;
		}
		ll flag=1;
		for(ll i=1;i<=m;i++)
		{
			if(!vis[x[i]]&&!vis[y[i]]) 
			{
				flag=0;
				break;
			}
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
