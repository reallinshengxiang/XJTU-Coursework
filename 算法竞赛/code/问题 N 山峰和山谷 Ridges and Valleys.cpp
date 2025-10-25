#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	ll x,y;
};
point p;
ll high,low,vis[1010][1010],a[1010][1010],n;
ll dx[8]={0,0,1,1,1,-1,-1,-1};
ll dy[8]={1,-1,0,-1,1,0,-1,1};
void bfs(ll x,ll y)
{
	vis[x][y]=1;
	ll flaghigh=0,flaglow=0;
	deque<point> dq;
	dq.push_back((point){x,y});
	while(!dq.empty())
	{
		p=dq.front();
		dq.pop_front();
		for(ll i=0;i<=7;i++)
		{
			ll nx=p.x+dx[i];
			ll ny=p.y+dy[i];
			if(nx>=1&&ny>=1&&nx<=n&&ny<=n)
			{
				if(a[nx][ny]==a[p.x][p.y]&&!vis[nx][ny])
				{
					vis[nx][ny]=1;
					dq.push_back((point){nx,ny});
				}
				else if(a[nx][ny]>a[p.x][p.y]) flaghigh=1;
				else if(a[nx][ny]<a[p.x][p.y]) flaglow=1;
			}
		}
	}
	if(!flaghigh&&!flaglow) 
	{
		high++;
		low++;
	}
	else if(!flaghigh&&flaglow) high++;
	else if(flaghigh&&!flaglow) low++;
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
			if(!vis[i][j]) bfs(i,j);
		}
	}
	cout<<high<<" "<<low;
	return 0;
}
