#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=310;
struct point{
	ll x,y,step;
	point(){}
	point(ll x,ll y,ll step):x(x),y(y),step(step){} 
};
point p;
queue<point> que;
ll dx[5]={0,0,1,-1};
ll dy[5]={1,-1,0,0};
ll vis[N][N],a[N][N],m,inf;
void bfs()
{
	que.push(point(0,0,0));
	vis[0][0]=1;
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		if(a[p.x][p.y]==inf)
		{
			cout<<p.step;
			return;
		}
		for(ll i=0;i<=3;i++)
		{
			ll x=p.x+dx[i];
			ll y=p.y+dy[i];
			if(x>=0&&y>=0&&!vis[x][y])
			{
				if(p.step+1>=a[x][y]) continue;
				vis[x][y]=1;
				que.push(point(x,y,p.step+1));
			}
		}
	}
	cout<<"-1";
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m;
	memset(a,127,sizeof(a));
	inf=a[0][0];
	while(m--)
	{
		ll x,y,t;
		cin>>x>>y>>t;
		a[x][y]=min(a[x][y],t);
		for(ll i=0;i<=3;i++)
		{
			ll xx=x+dx[i];
			ll yy=y+dy[i];
			if(xx>=0&&yy>=0) a[xx][yy]=min(a[xx][yy],t);
		}
	}
	bfs();
	return 0;
}
