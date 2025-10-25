#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1010;
struct point{
	ll x,y,step;
	point(){}
	point(ll x,ll y,ll step):x(x),y(y),step(step){}
}; 
point p1,p2,p,grass[N*N];
ll dx[5]={0,0,1,-1};
ll dy[5]={1,-1,0,0};
ll vis[N][N],ans,dis1[N][N],dis2[N][N],a[N][N],w,h,cnt;
void bfs1(ll x,ll y)
{
	queue<point> que;
	que.push(point(x,y,0));
	vis[x][y]=1;
	dis1[x][y]=0;
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		dis1[p.x][p.y]=p.step;
		for(ll i=0;i<=3;i++)
		{
			ll xx=p.x+dx[i];
			ll yy=p.y+dy[i];
			if(xx>=1&&xx<=h&&yy>=1&&yy<=w&&!vis[xx][yy]&&a[xx][yy]!=1)
			{
				vis[xx][yy]=1;
				que.push(point(xx,yy,p.step+1));
			}
		}
	} 
}
void bfs2(ll x,ll y)
{
	queue<point> que;
	que.push(point(x,y,0));
	memset(vis,0,sizeof(vis));
	vis[x][y]=1;
	dis2[x][y]=0;
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		dis2[p.x][p.y]=p.step;
		for(ll i=0;i<=3;i++)
		{
			ll xx=p.x+dx[i];
			ll yy=p.y+dy[i];
			if(xx>=1&&xx<=h&&yy>=1&&yy<=w&&!vis[xx][yy]&&a[xx][yy]!=1)
			{
				vis[xx][yy]=1;
				que.push(point(xx,yy,p.step+1));
			}
		}
	} 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>w>>h;	
	for(ll i=1;i<=h;i++)
	{
		for(ll j=1;j<=w;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==2) p1=point(i,j,0);
			else if(a[i][j]==3) p2=point(i,j,0);
			else if(a[i][j]==4)
			{
				cnt++;
				grass[cnt]=point(i,j,0);
			}
		}
	}
	memset(dis1,127/3,sizeof(dis1));
	memset(dis2,127/3,sizeof(dis2));
	ans=dis1[0][0];
	bfs1(p1.x,p1.y);
	bfs2(p2.x,p2.y);
	for(ll i=1;i<=cnt;i++) ans=min(ans,dis1[grass[i].x][grass[i].y]+dis2[grass[i].x][grass[i].y]);
	cout<<ans;
	return 0;
}
