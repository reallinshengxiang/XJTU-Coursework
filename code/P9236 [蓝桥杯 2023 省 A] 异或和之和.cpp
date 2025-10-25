#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,p[N][22],ans,sum[N],x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)  
	{
		cin>>x;
		sum[i]=sum[i-1]^x;
	}
	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=20;j++) p[j][(sum[i]>>j)&1]++;
	}
	for(ll i=0;i<=20;i++) ans=ans+p[i][0]*p[i][1]*(1<<i);
	cout<<ans;
	return 0;
}
