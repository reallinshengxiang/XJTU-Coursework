#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=55;
struct point{
	ll x,y;
	point(ll xx=0,ll yy=0):x(xx),y(yy){}
};
point st,ed,p;
ll dx[5]={0,0,1,-1};
ll dy[5]={1,-1,0,0}; 
ll a[N][N],r,c,xx,yy,vis[N][N],b[N][N],flag,ans,vv[N][N];
string s;
void bfs(point st,point ed)
{
	deque<point> que;
	que.push_back(st);
	vis[st.x][st.y]=1;
	while(!que.empty())
	{
		p=que.front();
		que.pop_front();
		if(a[p.x][p.y]==1)
		{
			for(ll i=0;i<=3;i++)
			{
				xx=p.x+dx[i];
				yy=p.y+dy[i];
				if(!vis[xx][yy]&&1<=xx&&xx<=r&&1<=yy&&yy<=c&&a[xx][yy]!=0)
				{
					if(xx==ed.x&&yy==ed.y) flag=1;
					que.push_back(point(xx,yy));
					vis[xx][yy]=1;
				}
			}
		}
		else if(a[p.x][p.y]==2)
		{
			for(ll i=0;i<=1;i++)
			{
				xx=p.x+dx[i];
				yy=p.y+dy[i];
				if(!vis[xx][yy]&&1<=xx&&xx<=r&&1<=yy&&yy<=c&&a[xx][yy]!=0)
				{
					if(xx==ed.x&&yy==ed.y) flag=1;
					que.push_back(point(xx,yy));
					vis[xx][yy]=1;
				}
			}
		}
		else if(a[p.x][p.y]==3)
		{
			for(ll i=2;i<=3;i++)
			{
				xx=p.x+dx[i];
				yy=p.y+dy[i];
				if(!vis[xx][yy]&&1<=xx&&xx<=r&&1<=yy&&yy<=c&&a[xx][yy]!=0)
				{
					if(xx==ed.x&&yy==ed.y) flag=1;
					que.push_back(point(xx,yy));
					vis[xx][yy]=1;
				}
			}
		}
		else if(a[p.x][p.y]==4)
		{
			for(ll i=2;i<=2;i++)
			{
				xx=p.x+dx[i];
				yy=p.y+dy[i];
				if(!vis[xx][yy]&&1<=xx&&xx<=r&&1<=yy&&yy<=c&&a[xx][yy]!=0)
				{
					if(xx==ed.x&&yy==ed.y) flag=1;
					que.push_back(point(xx,yy));
					vis[xx][yy]=1;
				}
			}
		}
	}
	if(!vis[ed.x][ed.y]) flag=0;
	else flag=1;
}
void print()
{
	for(ll i=1;i<=r;i++)
	{
		for(ll j=1;j<=c;j++) cout<<vis[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>r>>c;
	for(ll i=1;i<=r;i++)
	{
		cin>>s;
		for(ll j=1;j<=c;j++)
		{
			if(s[j-1]=='#') a[i][j]=0;
			else if(s[j-1]=='+') a[i][j]=1;
			else if(s[j-1]=='-') a[i][j]=2;
			else if(s[j-1]=='|') a[i][j]=3;
			else if(s[j-1]=='.') a[i][j]=4;
			else if(s[j-1]=='S') 
			{
				a[i][j]=1;
				st.x=i;
				st.y=j;
			}
			else if(s[j-1]=='T')
			{
				a[i][j]=1;
				ed.x=i;
				ed.y=j;
			}
		}
	}
	bfs(st,ed);
	if(flag==0)
	{
		cout<<"I'm stuck!";
		return 0;
	}
	for(ll i=1;i<=r;i++)
	{
		for(ll j=1;j<=c;j++) vv[i][j]=vis[i][j];
	}
	for(ll i=1;i<=r;i++)
	{
		for(ll j=1;j<=c;j++)
		{
			if(vv[i][j])
			{
				flag=0;
				memset(vis,0,sizeof(vis));
				bfs(point(i,j),ed);
				if(flag==0) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
