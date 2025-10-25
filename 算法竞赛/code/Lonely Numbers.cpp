#include<bits/stdc++.h>
using namespace std;
#define ll int
#pragma GCC optimize(2)
const ll N=1e6+10,M=1e6;
ll vis[N],prime[N],sum[N],T,n;
void euler()
{
	ll cnt=0;
	for(ll i=2;i<=M;i++)
	{
		if(!vis[i]) prime[++cnt]=i;
		for(ll j=1;j<=cnt;j++)
		{
			if(i*prime[j]>M) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	sum[1]=1;
	for(ll i=1;i<=cnt;i++)
	{
		if(prime[i]<=1000) sum[prime[i]*prime[i]]--;
		sum[prime[i]]++;
	}
	for(ll i=1;i<=M;i++) sum[i]=sum[i]+sum[i-1];
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	scanf("%d",&T);
	euler();
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",sum[n]);
	}
	return 0;
}