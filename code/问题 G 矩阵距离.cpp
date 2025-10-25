#include<bits/stdc++.h>
#include<deque>
using namespace std;
#define ll long long
struct node{
	ll x,y;
};
ll dx[4]={0,0,-1,1};
ll dy[4]={1,-1,0,0};
deque<node> q;
node aa,bb; 
string s;
ll a[1010][1010],dis[1010][1010],n,m,xx,yy;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(dis,-1,sizeof(dis));
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		for(ll j=1;j<=m;j++) 
		{
			a[i][j]=s[j-1]-'0'; 
			if(a[i][j])
			{
				aa.x=i;
			    aa.y=j;
			    q.push_back(aa);
			    dis[i][j]=0;
			}		
		}
	}
	while(!q.empty())
	{
		bb=q.front();
		q.pop_front();
		for(ll i=0;i<=3;i++)
		{
			xx=bb.x+dx[i];
			yy=bb.y+dy[i];
		
			if(dis[xx][yy]==-1&&xx>=1&&xx<=n&&yy>=1&&yy<=m)
			{
				dis[xx][yy]=dis[bb.x][bb.y]+1;
				aa.x=xx;
				aa.y=yy;
				q.push_back(aa);
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cout<<dis[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
