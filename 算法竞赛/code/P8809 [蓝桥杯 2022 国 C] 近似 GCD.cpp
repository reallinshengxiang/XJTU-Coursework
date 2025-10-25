#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,g,ans,sum[N],x,a[N],jj;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>g;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		if(x%g) a[i]=1;
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=1;i<=n-1;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			jj=j;
			if(sum[j]-sum[i-1]>1) break;
		}
		ans=ans+jj-i-1;
	}
	cout<<ans;
	return 0;
}
