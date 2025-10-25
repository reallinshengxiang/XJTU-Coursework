#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10,M=1e5+10;
ll n,k,ans,a[M],num[N][6];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=n;i>=1;i--)
	{
		if(num[a[i]%k][0]>=3) continue;
		num[a[i]%k][0]++;
		num[a[i]%k][num[a[i]%k][0]]=a[i];
	}
	for(ll i=0;i<=k-1;i++)
	{
		for(ll j=0;j<=k-1;j++)
		{
			for(ll sum=0;sum<=2*k;sum=sum+k)
			{
				ll x=sum-i-j;
				if(x<0||x>=k) continue;
				if(i!=j&&i!=x&&j!=x&&num[i][0]&&num[j][0]&&num[x][0]) ans=max(ans,num[i][1]+num[j][1]+num[x][1]);
				else if(i==j&&j==x&&num[i][0]>=3) ans=max(ans,num[i][1]+num[i][2]+num[i][3]);
				else if(i==j&&j!=x&&num[i][0]>=2&&num[x][0]>=1) ans=max(ans,num[i][1]+num[i][2]+num[x][1]);
				else if(i!=j&&j==x&&num[i][0]&&num[j][0]>=2) ans=max(ans,num[i][1]+num[j][1]+num[j][2]);
				else if(i!=j&&i==x&&num[i][0]>=2&&num[j][0]) ans=max(ans,num[i][1]+num[i][2]+num[j][1]);
			}
		}
	}
	cout<<ans;
	return 0;
}
