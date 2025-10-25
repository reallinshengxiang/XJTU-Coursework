#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll flag[55],q[5050],x[55],y[55],f[55][55],n;
ll check(ll x)
{
	ll head=1,tail=1;
	memset(flag,0,sizeof(flag));
	q[1]=1;
	flag[1]=1;
	while(head<=tail)
	{
		for(ll i=1;i<=n;i++)
		{
			if(!flag[i]&&f[q[head]][i]<=2*x)
			{
				flag[i]=1;
				tail++;
				q[tail]=i;
			}
		}
		head++;		
	}
	if(tail==n) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>x[i]>>y[i];
	for(ll i=1;i<=n-1;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			f[i][j]=f[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
		}
	}
	ll l=0,r=1000000010;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}
