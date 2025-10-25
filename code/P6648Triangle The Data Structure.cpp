#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e3+10;
ll n,k,a[N][N],sum1[N][N],sum2[N][N],sum3[N][N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=i;j++) cin>>a[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=i;j++) sum1[i][j]=sum1[i-1][j]+a[i][j],sum2[i][j]=sum2[i][j-1]+a[i][j],sum3[i][j]=sum3[i-1][j-1]+a[i][j];
	}
	for(ll i=k;i<=n;i++)
	{
		for(ll j=1;j<=i-k+1;j++) ans=max(ans,sum1[i][j]-sum1[i-k+1][j]+sum2[i][j+k-1]-sum2[i][j]+sum3[i][j+k-1]-sum3[i-k+1][j]-a[i][j]-a[i-k+1][j]-a[i][j+k-1]);
	}
	cout<<ans;
	return 0;
}
