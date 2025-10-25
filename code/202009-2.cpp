#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
ll a[N],sum[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,k,t,xl,yd,xr,yu,flag,x,y,ans1=0,ans2=0;
	cin>>n>>k>>t>>xl>>yd>>xr>>yu;
	while(n--)
	{
		memset(a,0,sizeof(a));
		flag=0;
		for(ll i=1;i<=t;i++)
		{
			cin>>x>>y;
			if(x>=xl&&x<=xr&&y>=yd&&y<=yu) a[i]=1;
			sum[i]=sum[i-1]+a[i];
			if(a[i]==1&&!flag) 	flag=1;
		}
		if(flag) ans1++;
		for(ll i=k;i<=t;i++) 
		{
			if(sum[i]-sum[i-k]==k) 
			{
				ans2++;
				break;
			}
		}
	}
	cout<<ans1<<"\n"<<ans2;
	return 0;
} 
