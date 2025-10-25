#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1510;
struct point{
	ll x,y,xx,yy;
	point(ll x=0,ll y=0,ll xx=0,ll yy=0):x(x),y(y),xx(xx),yy(yy){}
};
point st,p;
ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};
ll n,m,a[N][N],vis[N][N],ans;
string s;
ll bfs(point st)
{
	vis[st.x][st.y]=1;
	queue<point> q;
	map<ll,ll> mp;
	q.push(st);
	vis[st.x][st.y]=st.x*131+st.y*13;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(ll i=0;i<=3;i++)
		{
			ll x=(p.x+n+dx[i])%n;
			ll y=(p.y+m+dy[i])%m;
			ll xx=p.xx+dx[i];
			ll yy=p.yy+dy[i];
			if(a[x][y]) continue;
			if(vis[x][y]==0) vis[x][y]=xx*131+yy*13,q.push(point(x,y,xx,yy));
			else if(vis[x][y]!=xx*131+yy*13) return 1;
			
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m)
	{
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(ll i=0;i<=n-1;i++)
		{
			cin>>s;
			for(ll j=0;j<=m-1;j++)
			{
				if(s[j]=='#') a[i][j]=1;
				else if(s[j]=='S') st=point(i,j,i,j);
			}
		}
		ans=bfs(st);
        if(ans==1) cout<<"Yes\n";
        else cout<<"No\n";
	}   
	return 0;
 } 
