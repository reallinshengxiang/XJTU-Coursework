#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[110][110],b[110][110],c[110][110],n,m,p;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>a[i][j];
	}
	cin>>p;
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=p;j++) cin>>b[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=p;j++)  
		{
			for(ll k=1;k<=m;k++)  c[i][j]=c[i][j]+a[i][k]*b[k][j];
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=p;j++)  
		{
			cout<<c[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
