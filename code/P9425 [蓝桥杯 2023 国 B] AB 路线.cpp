#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
const ll N=1e3+10;
struct point{
	ll x,y;
};
point p;
string s;
ll a[N][N],dis[N][N],vis[N][N],tag[N][N],n,m,k;
ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};
void print()
{
	cout<<"\n";
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)cout<<dis[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}
ll bfs(point st)
{
	deque<point> dq;
	vis[st.x][st.y]=1;
	tag[st.x][st.y]=1;
	dis[st.x][st.y]=1;
	dq.push_back(st);
	while(!dq.empty())
	{
		p=dq.front();
		dq.pop_front();
		//print();
		for(ll i=0;i<=3;i++)
		{
			ll px=p.x+dx[i];
			ll py=p.y+dy[i];
			if(!(px>=1&&px<=n&&py>=1&&py<=m)) continue;
			if((dis[p.x][p.y]/k)%2==0)
			{
				if(!tag[px][py]&&a[px][py]==-1)
				{				
					dis[px][py]=dis[p.x][p.y]+1;
					if(px==n&&py==m) return dis[px][py];
					if(dis[px][py]%k==0) tag[px][py]=1;
					dq.push_back((point){px,py});
				}
			}
			else
			{
				if(!tag[px][py]&&a[px][py]==1)
				{				
					dis[px][py]=dis[p.x][p.y]+1;
					if(px==n&&py==m) return dis[px][py];
					if(dis[px][py]%k==0) tag[px][py]=1;
					dq.push_back((point){px,py});
				}				
			}
			//print();
		}
	}
	return dis[n][m];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++)
    {
    	cin>>s;
    	for(ll j=1;j<=m;j++)
    	{
    		if(s[j-1]=='A') a[i][j]=-1;
    		else a[i][j]=1;
		}
	}
	if(a[1][1]==1)
	{
		cout<<"-1";
		return 0;
	} 
	dis[n][m]=0;
	cout<<bfs((point){1,1})-1;
	return 0;
}
