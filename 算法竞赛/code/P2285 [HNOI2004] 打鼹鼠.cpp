#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct point{
	ll t,x,y;
}; 
point p[N];
ll n,m,dp[N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++) cin>>p[i].t>>p[i].x>>p[i].y;
	dp[0]=1;
	for(ll i=1;i<=m;i++)
	{
		dp[i]=1;
		for(ll j=1;j<=i-1;j++)
		{
			if(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)<=(p[i].t-p[j].t)) dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
