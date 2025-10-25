#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=220;
ll n,m,dis[N][N],v[N],mind,d,flag,inf,ans,ansi,k,nn;
map<ll,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(dis,127,sizeof(dis));
	inf=dis[0][0];
	mind=inf;
	for(ll i=1;i<=m;i++)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		dis[x][y]=dis[y][x]=w;
	}
	cin>>k;
	for(ll ii=1;ii<=k;ii++)
	{
		cin>>nn;
		flag=0;
		mp.clear();
		for(ll i=1;i<=nn;i++) 
		{
			cin>>v[i],mp[v[i]]++;
			if(mp[v[i]]!=1) flag=1;
		}
		v[nn+1]=0;		
		d=0;
		if(nn!=n) continue;
		for(ll i=0;i<=nn;i++)
		{
			if(dis[v[i]][v[i+1]]==inf) 
			{
				flag=1;
				break;
			}
			d=d+dis[v[i]][v[i+1]];
		//	cout<<i<<"  "<<v[i]<<"  "<<d<<"\n";
		}
		//cout<<"\n";
		if(!flag)
		{
			ans++;
			if(d<mind) 
			{
				ansi=ii;
				mind=d;
			}
		}
	 } 
	 cout<<ans<<"\n"<<ansi<<" "<<mind;
	return 0;
}
