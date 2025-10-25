#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=1e4+10;
struct point{
	ll x,y;
	bool operator<(const point a)
	{
		if(x<a.x) return 1;
		return 0;
	}
};
point p;
ll dx[5]={0,0,1,-1};
ll dy[5]={-1,1,0,0};
ll sum,ans,a[N][N],vis[N][N],n,m;
string s;
void bfs(ll x,ll y)
{
	sum++;
	vis[x][y]=1;
	ll flag=0;
	deque<point> dq;
	dq.push_back((point){x,y});
	if(a[x][y]>1) flag=1;
	while(!dq.empty())
	{
		p=dq.front();
		dq.pop_front();
		for(ll i=0;i<=3;i++)
		{
			ll px=p.x+dx[i];
			ll py=p.y+dy[i];
			if(!vis[px][py]&&px>=1&&px<=n&&py>=1&&py<=m&&a[px][py])
			{
				vis[px][py]=1;
				dq.push_back((point){px,py});
				if(a[px][py]>1) flag=1;
			}
		}
	}
	if(flag) ans++;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		for(ll j=1;j<=m;j++) a[i][j]=s[j-1]-'0';
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) 
		{
			if(a[i][j]&&!vis[i][j]) bfs(i,j);
		}
	}
	cout<<sum<<" "<<ans;
	return 0;
}
