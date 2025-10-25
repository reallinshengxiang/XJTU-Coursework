#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
struct point{
	ll x,y,color,step;
	point(){}
	point(ll x,ll y,ll color,ll step):x(x),y(y),color(color),step(step){}
	bool operator<(const point &a) const
	{return step>a.step;}
};
point p,pp;
priority_queue<point> que;
ll dx[13]={0,0,1,-1,1,1,-1,-1,0,0,2,-2};
ll dy[13]={1,-1,0,0,1,-1,1,-1,2,-2,0,0};
ll cost[13]={0,0,0,0,2,2,2,2,2,2,2,2};
ll a[N][N],dis[N][N],inf,n,m,x,y,c;
void bfs()
{
	dis[1][1]=0;
	que.push(point(1,1,a[1][1],dis[1][1]));
	while(!que.empty())
	{
		p=que.top();
		que.pop();
		if(dis[p.x][p.y]<p.step) continue;
		for(ll i=0;i<=11;i++)
		{
			pp.x=p.x+dx[i];
			pp.y=p.y+dy[i];
			pp.step=p.step+cost[i];
			if(pp.x>=1&&pp.x<=n&&pp.y>=1&&pp.y<=n)
			{
				pp.color=a[pp.x][pp.y];
				if(pp.color)
				{
					if(pp.color!=p.color) pp.step++;
					if(dis[pp.x][pp.y]>pp.step)
					{
						dis[pp.x][pp.y]=pp.step;
						que.push(point(pp.x,pp.y,pp.color,pp.step));
					}
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y>>c;
		c++;
		a[x][y]=c;
	}
	memset(dis,0x3f,sizeof(dis));
	inf=dis[0][0];
	bfs();
	if(a[n][n])
	{
		if(dis[n][n]==inf) cout<<"-1";
		else cout<<dis[n][n];
	}
	else
	{
		dis[n][n]=min(dis[n-1][n],dis[n][n-1])+2;
		if(dis[n][n]>=inf) cout<<"-1";
		else cout<<dis[n][n];
	}
	return 0;
}
