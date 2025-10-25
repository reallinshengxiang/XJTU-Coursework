#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=55;
struct point{
	ll x,y;
};
point p;
ll a[N][N],vis[N][N],n=30,m=50,w[N][N],px,py,ans[N*N],cnt;
ll dx[5]={1,0,0,-1};
ll dy[5]={0,-1,1,0};
string s;
void print()
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cout<<vis[i][j]<<" ";
		cout<<"\n";
	}
}
void bfs()
{
	deque<point> dq;
	dq.push_back((point){1,1});
	vis[1][1]=1;
	while(!dq.empty())
	{
		p=dq.front();
		dq.pop_front();
		for(ll i=0;i<=3;i++)
		{
			px=p.x+dx[i];
			py=p.y+dy[i];
			if(!a[px][py]&&px>=1&&px<=n&&py>=1&&py<=m&&vis[px][py]==0)
			{
				vis[px][py]=1;
				dq.push_back((point){px,py});
				w[px][py]=i;
			}			
		}
		if(vis[n][m]) break;
	}
	px=n,py=m;
	while(!(px==1&&py==1))
	{
		ans[++cnt]=w[px][py];
		px=px-dx[ans[cnt]];
		py=py-dy[ans[cnt]];
	}	
	for(ll i=cnt;i>=1;i--) 
	{
		if(ans[i]==0) cout<<"D";
		else if(ans[i]==1) cout<<"L";
		else if(ans[i]==2) cout<<"R";
		else cout<<"U";
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("1.txt","r",stdin);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		for(ll j=1;j<=m;j++) 
		{
			if(s[j-1]=='1') a[i][j]=1;
		}
	}
	bfs();
	//print();
}
