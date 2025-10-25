#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,m,a[N],lg2[N],dp[N][22];
void st_init()
{
	lg2[0]=-1;
	for(ll i=1;i<N;i++) lg2[i]=lg2[i>>1]+1;
	for(ll i=1;i<=n;i++) dp[i][0]=a[i];
	ll p=lg2[n];
	for(ll len=1;len<=p;len++)
	{
		for(ll s=1;s+(1<<len)<=n+1;s++) dp[s][len]=min(dp[s][len-1],dp[s+(1<<(len-1))][len-1]);
	}
} 
ll st_query(ll l,ll r)
{
	ll p=lg2[r-l+1],ans;
	ans=min(dp[l][p],dp[r-(1<<p)+1][p]);
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    st_init();
    for(ll i=m;i<=n;i++) cout<<st_query(i-m+1,i)<<"\n";
	return 0;
} 
