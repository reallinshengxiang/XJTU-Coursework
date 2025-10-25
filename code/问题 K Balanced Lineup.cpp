#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10,M=1e6+10;
ll h[N],dp1[N][22],dp2[N][22],lg2[M+1],n,q;
void st_init()
{
	lg2[0]=-1;
	for(ll i=1;i<=M;i++) lg2[i]=lg2[i>>1]+1;
	for(ll i=1;i<=n;i++) dp1[i][0]=dp2[i][0]=h[i];
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
ll st_query(ll l,ll r)
{
	ll k=lg2[r-l+1];
	return (max(dp1[l][k],dp1[r-(1<<k)+1][k])-min(dp2[l][k],dp2[r-(1<<k)+1][k]));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++) cin>>h[i];
	st_init();
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		cout<<st_query(l,r)<<"\n";
	}
	return 0;
}
