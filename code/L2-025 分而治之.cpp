#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
struct edge{
	ll a,b;
};
edge e[N];
ll n,m,k,np,v,vis[N],flag;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++) cin>>e[i].a>>e[i].b;
	cin>>k;
	while(k--)
	{
	    memset(vis,0,sizeof(vis));
		cin>>np;
		for(ll i=1;i<=np;i++) 
		{
			cin>>v;
			vis[v]=1;
		}
		flag=1;
		for(ll i=1;i<=m;i++)
		{
			if(!vis[e[i].a]&&!vis[e[i].b]) 
			{
				flag=0;
				break;
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
