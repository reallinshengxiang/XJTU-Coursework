#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	ll y,x;
	point(ll y=0,ll x=0):y(y),x(x){}
};
point p,pp;
const ll N=110;
ll dx[5]={0,0,-1,1};
ll dy[5]={1,-1,0,0};
char a[N][N];
ll vis[N][N],m,n,q,opt,x1,x2,y1,y2,x,y,px,py;
char ch;
void print()
{
	for(ll i=n-1;i>=0;i--)
	{
		for(ll j=0;j<=m-1;j++) cout<<a[i][j];
		cout<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n>>q;
	for(ll i=0;i<=n-1;i++)
	{
		for(ll j=0;j<=m-1;j++) a[i][j]='.';
	}
	while(q--)
	{
		cin>>opt;
		if(opt==0)
		{
			cin>>x1>>y1>>x2>>y2;
			if(x1==x2)
			{
				if(y1>y2) swap(y1,y2);
				for(ll i=y1;i<=y2;i++)
				{
					if(a[i][x1]=='-'||a[i][x1]=='+') a[i][x1]='+';
					else a[i][x1]='|';
				}
			}
			else
			{
				if(x1>x2) swap(x1,x2);
				for(ll i=x1;i<=x2;i++)
				{
					if(a[y1][i]=='|'||a[y1][i]=='+') a[y1][i]='+';
					else a[y1][i]='-';
				}
			}
		}
		else 
		{
			cin>>x>>y>>ch;
			memset(vis,0,sizeof(vis));
			deque<point> dq;
			dq.clear();
			vis[y][x]=1;
			a[y][x]=ch;
			dq.push_back((point(y,x)));
			while(!dq.empty())
			{
				p=dq.front();
				dq.pop_front();
				for(ll i=0;i<=3;i++)
				{
					py=p.y+dy[i];
					px=p.x+dx[i];				
					if(0<=px&&px<=m-1&&0<=py&&py<=n-1&&!vis[py][px]&&a[py][px]!='-'&&a[py][px]!='|'&&a[py][px]!='+')
					{
						vis[py][px]=1;
						pp.y=py,pp.x=px;
						dq.push_back(pp);
						a[py][px]=ch;
					}
				}
			}
		}
	}
	print();
	return 0;
 } 
