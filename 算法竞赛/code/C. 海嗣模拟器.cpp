#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	ll x,y;
	point(ll x=0,ll y=0):x(x),y(y){}
};
point p;
deque<point> que,qq; 
ll dx[5]={0,0,1,-1};
ll dy[5]={1,-1,0,0};
ll cnt,a[1010][1010],b[1010][1010],c[1010][1010],d[1010][1010],n,vis[1010][1010],ans;
void search1(ll xx,ll yy)
{
	deque<point> dq;
	ll color=a[xx][yy];
	b[xx][yy]=cnt;
	ll sum=1;
	que.push_back(point(xx,yy));
	dq.push_back(point(xx,yy));
	while(!que.empty())
	{
		for(ll i=0;i<=3;i++)
		{
			p=que.front();
			ll x=p.x+dx[i];
		    ll y=p.y+dy[i];		    
			if(x>=1&&x<=n&&y>=1&&y<=n&&!b[x][y]&&a[x][y]==color)
			{
				que.push_back(point(x,y));
				b[x][y]=cnt;
				sum++;
				dq.push_back(point(x,y));
			}
		}
		que.pop_front();
    }    
	for(ll i=0;i<=sum-1;i++) 
	{
		c[dq[i].x][dq[i].y]=sum;
		d[dq[i].x][dq[i].y]=cnt;
	}
	dq.push_front(point(0,sum));
}
void search2(ll xx,ll yy)
{
	ll zu=d[xx][yy];
	qq.push_back(point(xx,yy));
	ll sum=0;
	while(!qq.empty())
	{
		for(ll i=0;i<=3;i++)
		{
			p=qq.front();
			ll x=p.x+dx[i];
		    ll y=p.y+dy[i];  
			if(x>=1&&x<=n&&y>=1&&y<=n&&!vis[x][y]&&d[x][y]==zu)
			{
				qq.push_back(point(x,y));
				vis[x][y]=1;
			}
			else if(x>=1&&x<=n&&y>=1&&y<=n&&!vis[x][y]&&d[x][y]!=zu)  	sum=max(sum,c[x][y]);
		}
		qq.pop_front();
	}
	ans=max(ans,sum+c[xx][yy]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) cin>>a[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(!b[i][j])
			{
				cnt++;
				search1(i,j);
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(!vis[i][j]) search2(i,j);
		}
	}
	cout<<ans;
	return 0;
}
