#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e4+10;
ll n,q,a[N],lg2[N],dp_max[N][22],dp_min[N][22];
void st_init()
{
	lg2[0]=-1;
	for(ll i=1;i<N;i++) lg2[i]=lg2[i>>1]+1;
	for(ll i=1;i<=n;i++) dp_min[i][0]=dp_max[i][0]=a[i];
	ll p=lg2[n];
	for(ll k=1;k<=p;k++)
	{
		for(ll s=1;s+(1<<k)<=n+1;s++)
		{
			dp_max[s][k]=max(dp_max[s][k-1],dp_max[s+(1<<(k-1))][k-1]);
			dp_min[s][k]=min(dp_min[s][k-1],dp_min[s+(1<<(k-1))][k-1]);
		}
	}
}
ll st_query(ll l,ll r)
{
	ll k=lg2[r-l+1];
	ll x=max(dp_max[l][k],dp_max[r-(1<<k)+1][k]);
	ll y=min(dp_min[l][k],dp_min[r-(1<<k)+1][k]);
	return x-y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++) cin>>a[i];
	st_init();
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		cout<<st_query(l,r)<<"\n";
	 } 
	return 0;
}
