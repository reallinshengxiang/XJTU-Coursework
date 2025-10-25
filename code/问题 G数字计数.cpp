#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=15;
ll ten[22],dp[22],cnta[22],cntb[22],num[22],a,b;
void init()
{
	ten[0]=1;
	for(ll i=1;i<=N;i++)
	{
		dp[i]=i*ten[i-1];
		ten[i]=10*ten[i-1];
	}
}
void solve(ll x,ll *cnt)
{
	ll len=0;
	while(x)
	{
		len++;
		num[len]=x%10;
		x=x/10;
	}
	for(ll i=len;i>=1;i--)
	{
		for(ll j=0;j<=9;j++) cnt[j]=cnt[j]+dp[i-1]*num[i];
		for(ll j=0;j<=num[i]-1;j++) cnt[j]=cnt[j]+ten[i-1];
		ll num2=0;
		for(ll j=i-1;j>=1;j--) num2=num2*10+num[j];
		cnt[num[i]]=cnt[num[i]]+num2+1;
		cnt[0]=cnt[0]-ten[i-1];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin>>a>>b;
	solve(a-1,cnta);
	solve(b,cntb);
	for(ll i=0;i<=9;i++) cout<<cntb[i]-cnta[i]<<" ";
	return 0;
}
