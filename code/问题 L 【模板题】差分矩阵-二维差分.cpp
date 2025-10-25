#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,q,a[1100][1100],d[1100][1100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	ll x1,x2,y1,y2,c;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>a[i][j];
	}
	while(q--)
	{
		cin>>x1>>y1>>x2>>y2>>c;
		d[x1][y1]=d[x1][y1]+c;
		d[x1][y2+1]=d[x1][y2+1]-c;
		d[x2+1][y2+1]=d[x2+1][y2+1]+c;		
		d[x2+1][y1]=d[x2+1][y1]-c;
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)  
		{
			d[i][j]=d[i][j]+d[i-1][j]+d[i][j-1]-d[i-1][j-1];
			a[i][j]=a[i][j]+d[i][j];
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)  cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
