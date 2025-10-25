#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll n,m,a[N][N],b[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>a[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>b[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cout<<a[i][j]*b[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
