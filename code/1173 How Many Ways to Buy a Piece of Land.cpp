#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll x,ans,n,m,sum[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>x;
		sum[i]=sum[i-1]+x;
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;j++)
		{
			if(sum[j]-sum[i-1]<=m) ans++;
		}
	}
	cout<<ans;
	return 0;
}
