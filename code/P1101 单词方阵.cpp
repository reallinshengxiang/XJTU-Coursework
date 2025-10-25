#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
char a[N][N];
ll b[N][N],n;
string ss="yizhong",s;
ll dx[10]={0,0,1,-1,1,1,-1,-1};
ll dy[10]={1,-1,0,0,1,-1,1,-1};
void search(ll x,ll y)
{
	ll xx,yy,flag;
	for(ll i=0;i<=7;i++)
	{
		flag=1;
		for(ll j=1;j<=6;j++)
		{
			xx=x+j*dx[i];
			yy=y+j*dy[i];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&a[xx][yy]==ss[j]) continue;
			flag=0;
			break;
		}
		if(flag)
		{
			for(ll j=0;j<=6;j++)
		    {
			   xx=x+j*dx[i];
			   yy=y+j*dy[i];
			   b[xx][yy]=1;
		    }
		}
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
		for(ll j=1;j<=n;j++) a[i][j]=s[j-1];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(a[i][j]==ss[0]) search(i,j);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(b[i][j]) cout<<a[i][j];
			else cout<<"*";
		}
		cout<<"\n";
	}
	return 0;
}
