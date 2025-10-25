#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	ll x,y,z;
};
ll vis[66][1300][130],a[66][1300][130],sum,m,n,l,t;
ll dx[8]={0,0,1,0,0,-1};
ll dy[8]={0,1,0,0,-1,0};
ll dz[8]={1,0,0,-1,0,0}; 
ll bfs(ll x,ll y,ll z)
{
	deque<point> dq;
	dq.push_back((point){x,y,z});
	ll cnt=1;
	vis[x][y][z]=1;
	while(!dq.empty())
	{
		point p=dq.front();
		dq.pop_front();
		for(ll i=0;i<=5;i++)
		{
			ll px=p.x+dx[i];
			ll py=p.y+dy[i];
			ll pz=p.z+dz[i];
			if(px>=1&&px<=l&&py>=1&&py<=m&&pz>=1&&pz<=n&&!vis[px][py][pz]&&a[px][py][pz])
			{
				vis[px][py][pz]=1;
				dq.push_back((point){px,py,pz});
				cnt++;
			} 
		}
	}
	if(cnt<t) return 0;
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n>>l>>t;
	for(ll i=1;i<=l;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			for(ll k=1;k<=n;k++) cin>>a[i][j][k];
		}
	}
	for(ll i=1;i<=l;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			for(ll k=1;k<=n;k++)
			{
				if(!vis[i][j][k]&&a[i][j][k]) sum=sum+bfs(i,j,k);
			}
		}
	}
	cout<<sum;
	return 0;
}
