#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=310;
struct point{
	ll x,y,step;
	point(){}
	point(ll x,ll y,ll step):x(x),y(y),step(step){}
};
struct transport{
	ll x1,y1,x2,y2;
};
transport tp[30];
queue<point> que;
point p;
ll dx[5]={0,0,1,-1};
ll dy[5]={1,-1,0,0};
ll vis[N][N],a[N][N],n,m,ff[30];
string s;
void search(ll x,ll y)
{
	que.push(point(x,y,0));
	vis[x][y]=1;
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		if(a[p.x][p.y]==-2)
		{
			cout<<p.step;
			return;
		}
		if(a[p.x][p.y]>=1&&a[p.x][p.y]<=26)
		{
			ll xx=p.x,yy=p.y;
			if(xx==tp[a[xx][yy]].x1&&yy==tp[a[xx][yy]].y1)
			{
				p.x=tp[a[xx][yy]].x2;
				p.y=tp[a[xx][yy]].y2;
			}
			else
			{
				p.x=tp[a[xx][yy]].x1;
				p.y=tp[a[xx][yy]].y1;
			}
		}
		for(ll i=0;i<=3;i++)
		{
			ll xx=p.x+dx[i];
			ll yy=p.y+dy[i];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]&&a[xx][yy]!=0)
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
	cin>>n>>m;
	ll x,y;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		for(ll j=1;j<=m;j++) 
		{
			if(s[j-1]=='#') a[i][j]=0;
			else if(s[j-1]=='.') a[i][j]=-1;
			else if(s[j-1]=='=') a[i][j]=-2;
			else if(s[j-1]=='@') 
			{
				a[i][j]=-3;
				x=i;
				y=j;
			}
			else 
			{
				a[i][j]=s[j-1]-'A'+1;
				ff[a[i][j]]++;
				if(ff[a[i][j]]==1) 
				{
					tp[a[i][j]].x1=i;
					tp[a[i][j]].y1=j;
				}
				else
				{
					tp[a[i][j]].x2=i;
					tp[a[i][j]].y2=j;
				}
			}
		}
	}
	search(x,y);
	return 0;
}
