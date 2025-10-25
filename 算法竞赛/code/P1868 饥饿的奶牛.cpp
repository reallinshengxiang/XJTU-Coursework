#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e6+10;
vector<ll> qj[N];
ll dp[N],n,maxx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		qj[y].push_back(x);
		maxx=max(maxx,y);
	}
	for(ll i=1;i<=maxx;i++)
	{
		dp[i]=dp[i-1];
		for(ll j=0;j<qj[i].size();j++)
		{
			ll x=qj[i][j];
			dp[i]=max(dp[i],dp[x-1]+i-x+1);
		}
	}
	cout<<dp[maxx];
	return 0;
}
