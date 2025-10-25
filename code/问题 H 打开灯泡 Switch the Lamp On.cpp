#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dir[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}};
ll ab[4]={2,1,1,2};
ll cd[4][3]={{-1,-1},{-1,0},{0,-1},{0,0}};
ll g[505][505],dis[505][505],n,m;
struct point{
	ll x,y,dis;
};
point p;
char ch;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(dis,0x3f,sizeof(dis));
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='/') g[i][j]=1;
			else g[i][j]=2;
		}
	}
	deque<point> dq;
	dq.push_back((point){1,1,0});
	dis[1][1]=0;
	while(!dq.empty())
	{
		p=dq.front();
		dq.pop_front();
		ll nx,ny;
		for(ll i=0;i<=3;i++)
		{
			nx=p.x+dir[i][0];
			ny=p.y+dir[i][1];
			ll d=0;
			if(g[p.x+cd[i][0]][p.y+cd[i][1]]!=ab[i]) d=1;
			if(nx&&ny&&nx<=n+1&&ny<=m+1&&dis[nx][ny]>dis[p.x][p.y]+d)
			{
				dis[nx][ny]=dis[p.x][p.y]+d;
				if(d==0) dq.push_front((point){nx,ny,dis[nx][ny]});
				else dq.push_back((point){nx,ny,dis[nx][ny]});
				if(nx==n+1&&ny==m+1) break;
			}
		}
	} 
	if(dis[n+1][m+1]!=4557430888798830399) cout<<dis[n+1][m+1];
	else cout<<"NO SOLUTION";
	return 0;
}
