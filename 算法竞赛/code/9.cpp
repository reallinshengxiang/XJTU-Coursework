#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};
ll n,m,ans,vis[110][110],b[110][110],a[110][110];
void dfs(ll x,ll y)
{
	vis[x][y]=1;
	//cout<<x<<"      "<<y<<"\n";
	for(ll i=0;i<=3;i++)
	{
		
		ll px=x+dx[i];
		ll py=y+dy[i];
		//cout<<px<<" "<<py<<"\n";
		if(1<=px&&px<=n&&1<=py&&py<=m&&a[px][py]<a[x][y])
		{
			if(vis[px][py]) 
			{
				b[x][y]=max(b[x][y],b[px][py]+1);
				//cout<<b[x][y]<<"  "<<x<<" "<<y<<"\n";
			}
			else  
			{
			   dfs(px,py);
			   b[x][y]=max(b[x][y],b[px][py]+1);	
			}
		}
	}
}
void print()
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cout<<b[i][j]<<" ";
		cout<<"\n"; 
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>a[i][j],b[i][j]=1;
	}
	//print();
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			if(!vis[i][j]) dfs(i,j);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) ans=max(b[i][j],ans);
	}
	//print();
	cout<<ans;
	return 0;
}
