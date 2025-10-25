#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[110],c[110],f[100010],dp[100010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		memset(f,0,sizeof(f));
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=n;i++) cin>>c[i];
		f[0]=1;
		for(ll i=1;i<=n;i++) 
		{
			memset(dp,0,sizeof(dp));
			for(ll j=a[i];j<=m;j++) 
			{
				if (!f[j]&&f[j - a[i]]&&dp[j - a[i]]<c[i]) 
				{
					f[j]=1;
					dp[j]=dp[j-a[i]]+1;
				}
			}
		}
		ll ans=0;
		for(ll i=1;i<=m;i++)
		{
			if(f[i]) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
