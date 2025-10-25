#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=220;
ll nv,ne,m,k,a[N],vis[N],qq[N],d[N][N],ans[N];
vector<ll> e[N]; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>nv>>ne;
	for(ll i=1;i<=ne;i++)
	{
		ll x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x); 
		d[x][y]=d[y][x]=1;
	}
	cin>>m;
	while(m--)
	{
		cin>>k;
		for(ll i=1;i<=nv;i++) vis[i]=0;
		for(ll i=1;i<=k;i++) cin>>a[i],vis[a[i]]=1;
		ll flag=1;
		for(ll i=1;i<=k;i++)
		{
			for(ll j=i+1;j<=k;j++)
			{
				if(!d[a[i]][a[j]]) flag=0;
			}
		}
		if(!flag) cout<<"Not a Clique";
		else 
		{
			ll flag=0;
			for(ll i=1;i<=nv;i++)
			{
				if(!vis[i])
				{
					ll f=1;
					for(ll j=1;j<=k;j++) 
					{
						if(!d[i][a[j]]) f=0;
					}
					if(f) flag=1;
				}
			}
			if(flag) cout<<"Not Maximal";
			else cout<<"Yes";
		}
		cout<<"\n";
	} 
	return 0;
}
