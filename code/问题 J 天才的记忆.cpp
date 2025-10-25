#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll a[N],dp[N][22],lg2[N+1],n,m;
void st_init()
{
	lg2[0]=-1;
	for(ll i=1;i<=N;i++) lg2[i]=lg2[i>>1]+1;
	for(ll i=1;i<=n;i++) dp[i][0]=a[i];
	ll p=lg2[n];
	for(ll i=1;i<=p;i++)
	{
		for(ll j=1;j+(1<<i)<=n+1;j++) dp[j][i]=max(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
	}
}
ll st_query(ll l,ll r)
{
	ll k=lg2[r-l+1];
	return max(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	st_init();
	cin>>m;
	while(m--)
	{
		ll l,r;
		cin>>l>>r;
		cout<<st_query(l,r)<<"\n"; 
	}
	return 0;
}
