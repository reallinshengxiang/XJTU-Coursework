#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=550;
ll a[N][N],n,m,k,sum[N][N],ans,l;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>a[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;j++)
		{
			l=1;
			for(ll r=1;r<=m;r++)
			{
				while(l<=r&&sum[j][r]-sum[j][l-1]-sum[i-1][r]+sum[i-1][l-1]>k)  l++;
				ans=ans+r-l+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
