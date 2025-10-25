#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10,D=22;
ll n,q[N][D],k[D][N],v[N][D],w[N],a[N],d,b[N][D];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>d;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=d;j++) cin>>q[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=d;j++) cin>>k[j][i];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=d;j++) cin>>v[i][j];
	}
	for(ll i=1;i<=n;i++) cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			a[j]=0;
			for(ll kk=1;kk<=d;kk++) a[j]=a[j]+q[i][kk]*k[kk][j];
			a[j]=a[j]*w[i];
		}
		for(ll j=1;j<=d;j++)
		{
			for(ll kk=1;kk<=n;kk++)  b[i][j]=b[i][j]+a[kk]*v[kk][j];
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=d;j++) cout<<b[i][j]<<" ";
		cout<<"\n"; 
	}
	return 0;
}
