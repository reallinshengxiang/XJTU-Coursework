#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
struct point{
	ll x,y,dis;
	point(ll xx=0,ll yy=0,ll dd=0):x(xx),y(yy),dis(dd){}
};
point p;
deque<point> dq;
ll dx[5]={0,0,-1,1};
ll dy[5]={1,-1,0,0};
ll ans,n,m,k,d,x,y,c,px,py,vis[N][N],f[N][N],b[N][N];
void bfs()
{
	while(!dq.empty())
	{
		p=dq.front();
		dq.pop_front();
		if(vis[p.x][p.y]&&f[p.x][p.y])	ans=ans+b[p.x][p.y]*p.dis;
		for(ll i=0;i<=3;i++)
		{
			px=p.x+dx[i];
			py=p.y+dy[i];
			if(1<=px&&px<=n&&1<=py&&py<=n&&!vis[px][py])
			{
				vis[px][py]=1;
				dq.push_back((point(px,py,p.dis+1)));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k>>d;
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y;
		vis[x][y]=1;
		p.x=x,p.y=y;
		dq.push_back(p);
	}	
	for(ll i=1;i<=k;i++)
	{
		cin>>x>>y>>c;
		f[x][y]=1;
		b[x][y]=b[x][y]+c;
	}
	for(ll i=1;i<=d;i++)
	{
		cin>>x>>y;
		vis[x][y]=1;
	}
	bfs();
	cout<<ans;
	return 0;
}
