#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll lg2[N],a[N],dp1[N][22],dp2[N][22],n,k;
void st_init()
{
	lg2[0]=-1;
	for(ll i=1;i<=N;i++) lg2[i]=lg2[i>>1]+1;
	for(ll i=1;i<=n;i++) dp1[i][0]=dp2[i][0]=a[i];
	ll p=lg2[n];	
	for(ll i=1;i<=p;i++)
	{
		for(ll j=1;j+(1<<i)<=n+1;j++)
		{
			dp1[j][i]=max(dp1[j][i-1],dp1[j+(1<<(i-1))][i-1]);
			dp2[j][i]=min(dp2[j][i-1],dp2[j+(1<<(i-1))][i-1]);
		}
	}
}
ll st_query1(ll l,ll r)
{
	ll k=lg2[r-l+1];
	ll x=max(dp1[l][k],dp1[r-(1<<k)+1][k]);
	return x;
}
ll st_query2(ll l,ll r)
{
	ll k=lg2[r-l+1];
	ll x=min(dp2[l][k],dp2[r-(1<<k)+1][k]);
	return x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	st_init();
	for(ll i=1;i<=n-k+1;i++)  cout<<st_query1(i,i+k-1)<<" "<<st_query2(i,i+k-1)<<"\n";
	return 0;
}
