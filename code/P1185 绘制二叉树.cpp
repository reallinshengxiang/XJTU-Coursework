#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=800;
ll f[N][2*N],n,m,k,p,x,y;
char c[N][N*2];
void dfs(ll x,ll y,ll a,ll b,ll k,ll xx,ll yy)
{
	if(x==n)
	{
		c[x][y]='o';
		return;
	}
	if(k==1) 
	{
		c[x][y]='o';
		ll x1=xx+1,y1=yy*2-1;
		if(f[x1][y1]==0) dfs(x+1,y-1,a+1,b,2,x1,y1);
		x1=xx+1,y1=yy*2;
		if(!f[x1][y1]) dfs(x+1,y+1,a+1,b,3,x1,y1);
	}
	else if(k==2)
	{
		c[x][y]='/';
		if(a*2==b) dfs(x+1,y-1,1,a,1,xx,yy);
		else dfs(x+1,y-1,a+1,b,2,xx,yy);
	}
	else if(k==3)
	{
		c[x][y]='\\';
		if(a*2==b) dfs(x+1,y+1,1,a,1,xx,yy);
        else    dfs(x+1,y+1,a+1,b,3,xx,yy);
	}
}
void draw(ll k)
{
	n=3;
	for(ll i=3;i<=k;i++) n=n*2;
	m=6*(1<<(k-2))-1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) c[i][j]=' ';
	}
	dfs(1,m/2+1,1,n,1,1,1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k>>p;
	while(p--)
	{
		cin>>x>>y;
		f[x][y]=1;
	}
	if(k==1)
	{
		n=m=1;
		if(!f[1][1]) c[1][1]='o';
	}
	else draw(k);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cout<<c[i][j];
		cout<<"\n";
	}
	return 0;
}
