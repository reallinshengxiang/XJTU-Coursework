#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=130;
ll a[N][N],sum[N][N],n,ans=-128;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) cin>>a[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			for(ll k=i+1;k<=n;k++)
			{
				for(ll g=j+1;g<=n;g++) ans=max(ans,sum[k][g]+sum[i-1][j-1]-sum[i-1][g]-sum[k][j-1]);
			}
		}
	}
	cout<<ans;
	return 0;
}
