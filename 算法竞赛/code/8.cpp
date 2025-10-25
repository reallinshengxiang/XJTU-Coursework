#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll a[N][N],sum[N][N],n,m,t,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll r1,c1,r2,c2;
	cin>>n>>m>>t;
	for(ll i=1;i<=t;i++)
	{
		cin>>r1>>c1>>r2>>c2;
		a[r1][c1]++;
		a[r1][c2+1]--;
		a[r2+1][c1]--;
		a[r2+1][c2+1]++;
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
			if(!sum[i][j]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
