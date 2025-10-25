#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=55;
struct point{
	ll x,y,towards,step;
	point(){}
	point(ll x,ll y,ll towards,ll step):x(x),y(y),towards(towards),step(step){}
	bool operator<(const point &a) const
	{return step>a.step;}
};
point p;
priority_queue<point> que;
ll dx[5]={0,1,0,-1};
ll dy[5]={1,0,-1,0};
ll vis[N][N][5],n,m,a[N][N];
void bfs(ll x1,ll y1,ll x2,ll y2,ll sto)
{
	for(ll i=0;i<=3;i++) 
	{
		ll step=1;
		if(i==2) step=2;
		else if(i==0) step=0;
	    que.push(point(x1,y1,(sto+i)%4,step));	
	    vis[x1][y1][(sto+i)%4]=1;
	}
	while(!que.empty())
	{
		p=que.top();
		que.pop();
		if(p.x==x2&&p.y==y2)
		{
			cout<<p.step;
			return;
		}
		for(ll i=1;i<=3;i++)
		{
			ll xx=p.x+i*dx[p.towards];
			ll yy=p.y+i*dy[p.towards];			
			if(xx>=1&&xx<=n-1&&yy>=1&&yy<=m-1&&!vis[xx][yy][p.towards])
			{ 
			    ll flag=1; 
			    for(ll j=1;j<=i;j++)
			    {
			    	if(a[p.x+j*dx[p.towards]][p.y+j*dy[p.towards]]==1) 
					{
						flag=0;
						break;
					}
				}
				if(flag==0) continue;
				vis[xx][yy][p.towards]=1;
				for(ll j=0;j<=3;j++) 
	            { 
		           ll step=1;
		           if(j==2) step=2;
		           else if(j==0) step=0;
	               que.push(point(xx,yy,(p.towards+j)%4,p.step+step+1));	
	            }
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
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			ll xx;
			cin>>xx;
			if(xx) a[i-1][j-1]=a[i-1][j]=a[i][j-1]=a[i][j]=1;
		}
	}
	ll x1,y1,x2,y2,sto;
	char ch;
	cin>>x1>>y1>>x2>>y2>>ch;
	if(ch=='E') sto=0;
	else if(ch=='S') sto=1;
	else if(ch=='W') sto=2;
	else sto=3;
	bfs(x1,y1,x2,y2,sto);
	return 0;
}
