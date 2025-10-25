#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dx[10]={0,0,1,1,1,-1,-1,-1};
ll dy[10]={1,-1,0,1,-1,0,1,-1};
ll n,m,a[110][110],b[110][110];
string s;
void search(ll xx,ll yy)
{
	ll x,y,ans=0;
	for(ll i=0;i<=7;i++)
	{
		x=xx+dx[i];
		y=yy+dy[i];
		if(x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]) b[xx][yy]++;
	}
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
			if(s[j-1]=='*') a[i][j]=1;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)  search(i,j);
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			if(!a[i][j]) cout<<b[i][j];
			else cout<<"*";
		}
		cout<<"\n";
	}
	return 0;
}
