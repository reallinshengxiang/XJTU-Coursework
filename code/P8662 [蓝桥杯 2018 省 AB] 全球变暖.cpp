#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
struct point{
	ll x,y;
};
point p;
ll a[N][N],vis[N][N],cnt,px,py,n,sum;
ll dx[5]={0,0,-1,1};
ll dy[5]={1,-1,0,0};
string s;
map<ll,ll> mp;
void bfs(ll x,ll y)
{
	cnt++;
	a[x][y]=cnt;
	deque<point> dq;
	dq.push_back((point){x,y});
	vis[x][y]=1;
	while(!dq.empty())
	{
		p=dq.front();
		dq.pop_front();
		for(ll i=0;i<=3;i++)
		{
			px=p.x+dx[i];
			py=p.y+dy[i];
			if(1<=px&&px<=n&&1<=py&&py<=n&&!vis[px][py]&&a[px][py]==-1)
			{
				vis[px][py]=1;
				dq.push_back((point){px,py});
				a[px][py]=cnt;
			}
		}
	}
}
ll check(ll x,ll y)
{
	if(a[x-1][y]==0||a[x+1][y]==0||a[x][y-1]==0||a[x][y+1]==0) return 1;
	return 0;
}
void bfs2(ll x,ll y)
{
	deque<point> dq;
	dq.push_back((point){x,y});
	memset(vis,0,sizeof(vis));
	vis[x][y]=1;
	if(check(x,y)) a[x][y]=-a[x][y];
	while(!dq.empty())
	{
		p=dq.front();
		dq.pop_front();
		for(ll i=0;i<=3;i++)
		{
			px=p.x+dx[i];
			py=p.y+dy[i];
			if(1<=px&&px<=n&&1<=py&&py<=n&&!vis[px][py]&&a[px][py]!=0)
			{
				vis[px][py]=1;
				dq.push_back((point){px,py});
				if(check(px,py)) a[px][py]=-a[px][py];
			}
		}
	}
}
void print()
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		for(ll j=1;j<=n;j++)
		{
			if(s[j-1]=='#') a[i][j]=-1;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(a[i][j]==-1) bfs(i,j);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(a[i][j]>0&&!mp[a[i][j]]) 
			{
				mp[a[i][j]]=1;
				bfs2(i,j);
			}
		}
	}
	mp.clear();
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(a[i][j]>0&&!mp[a[i][j]])
			{
				mp[a[i][j]]=1;
				sum++;
			}
		}
	}
	cout<<cnt-sum;
	return 0;
}
