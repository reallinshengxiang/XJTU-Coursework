#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dx[8]={-2,-2,-1,-1,1,1,2,2};
ll dy[8]={1,-1,2,-2,2,-2,1,-1};
struct point{
	ll x,y;
};
point p;
ll d1[310][310],d2[310][310],L,vis[310][310][3],n;
ll bfs(point p1,point p2)
{
	if(p1.x==p2.x&&p1.y==p2.y) return 0;
	p1.x++;
	p1.y++;
	p2.x++;
	p2.y++;
	deque<point> dq1,dq2;
	vis[p1.x][p1.y][1]=1;
	vis[p2.x][p2.y][2]=1;
	dq1.push_back(p1);
	dq2.push_back(p2);
	while(dq1.size()&&dq2.size())
	{
		if(dq1.size()<dq2.size())
		{
			p=dq1.front();
			dq1.pop_front();
			for(ll i=0;i<=7;i++)
			{
				ll nx=p.x+dx[i];
				ll ny=p.y+dy[i];
				if(nx>=1&&ny>=1&&nx<=L&&ny<=L&&!vis[nx][ny][1])
				{
					dq1.push_back((point){nx,ny});
					d1[nx][ny]=d1[p.x][p.y]+1;
					vis[nx][ny][1]=1;
					if(vis[nx][ny][2]) return d1[nx][ny]+d2[nx][ny];
				}
			}
		}
		else
		{
			p=dq2.front();
			dq2.pop_front();
			for(ll i=0;i<=7;i++)
			{
				ll nx=p.x+dx[i];
				ll ny=p.y+dy[i];
				if(nx>=1&&ny>=1&&nx<=L&&ny<=L&&!vis[nx][ny][2])
				{
					dq2.push_back((point){nx,ny});
					d2[nx][ny]=d2[p.x][p.y]+1;
					vis[nx][ny][2]=1;
					if(vis[nx][ny][1])  return d2[nx][ny]+d1[nx][ny];
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		point p1,p2;
		cin>>L>>p1.x>>p1.y>>p2.x>>p2.y;
		memset(vis,0,sizeof(vis));
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2)); 
		cout<<bfs(p1,p2)<<"\n";
	}
	return 0;
}
