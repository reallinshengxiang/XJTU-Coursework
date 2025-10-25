#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dx[5]={0,0,-1,1};
ll dy[5]={1,-1,0,0};
ll que[1010][3],vis[35][35],a[35][35],dis[22][22],n,m,ans,cnt,b[22];
string s;
struct point{
	ll x,y;
};
point p[22];
ll search(ll x1,ll y1,ll x2,ll y2)
{
	memset(vis,0,sizeof(vis));
	vis[x1][y1]=1;
	ll head=1,tail=1;
	que[head][1]=x1;
	que[head][2]=y1;
	que[head][3]=0;
	if(vis[x2][y2])	 return 0;
	while(head<=tail)
	{
		for(ll i=0;i<=3;i++)
		{
			ll x=que[head][1]+dx[i];
			ll y=que[head][2]+dy[i];
			if(!vis[x][y]&&a[x][y]&&x>=1&&x<=n&&y>=1&&y<=m)
			{
				tail++;
				que[tail][1]=x;
				que[tail][2]=y;
				que[tail][3]=que[head][3]+1;
				vis[x][y]=1;
				if(vis[x2][y2])	return que[tail][3];
			}
		}
		head++;
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		for(ll j=1;j<=m;j++)
		{
			if(s[j-1]=='p') 
			{
				p[0].x=i;
				p[0].y=j;
				a[i][j]=1;
			}
			else if(s[j-1]=='.') a[i][j]=1;
			else if(s[j-1]=='#') a[i][j]=0;
			else if(s[j-1]=='@')
			{
				cnt++;
				p[cnt].x=i;
				p[cnt].y=j;
				a[i][j]=1;
			}
		}
	}
	for(ll i=0;i<=cnt;i++)
	{
		for(ll j=0;j<=i;j++)  
		{
			dis[i][j]=dis[j][i]=search(p[i].x,p[i].y,p[j].x,p[j].y);
			if(dis[i][j]==-1) 
			{
				cout<<"-1";
				return 0;
			}
		}
	}
	for(ll i=1;i<=cnt;i++) b[i]=i;
	ll sum;
	sum=dis[0][b[1]];
	for(ll i=1;i<=cnt-1;i++) sum=sum+dis[b[i]][b[i+1]];
	ans=sum;
	do{
		sum=dis[0][b[1]];
		for(ll i=1;i<=cnt-1;i++) sum=sum+dis[b[i]][b[i+1]];
		ans=min(sum,ans);
	}while(next_permutation(b+1,b+cnt+1));
	cout<<ans;
	return 0;
}
