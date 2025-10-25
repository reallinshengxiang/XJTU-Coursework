#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,dis[55][55][1010],a,b,w,inf,x,y,q,flag;
double ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
    memset(dis,127,sizeof(dis));
    inf=dis[0][0][0];
    for(ll i=1;i<=m;i++)
    {
    	cin>>a>>b>>w;
    	dis[a][b][1]=min(dis[a][b][1],w);
	}
	for(ll l=2;l<=m;l++)
	{
		for(ll k=1;k<=n;k++)
		{
			for(ll i=1;i<=n;i++)
			{
				if(dis[i][k][l-1]==inf) continue;
				for(ll j=1;j<=n;j++)
				{
					if(dis[k][j][1]==inf) continue;
					dis[i][j][l]=min(dis[i][j][l],dis[i][k][l-1]+dis[k][j][1]);
				}
			}
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		ans=inf;
		flag=1;
		for(ll i=1;i<=n;i++)
		{
			if(dis[x][y][i]<inf) 
			{
				flag=0;
				ans=min(ans,double(dis[x][y][i])/double(i));
			}
		}
		if(flag) cout<<"OMG!\n";
		else cout<<fixed<<setprecision(3)<<ans<<"\n";
	}
	return 0;
}
