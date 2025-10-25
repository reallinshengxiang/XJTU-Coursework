#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e4+10;
struct line{
	ll st,ed,dis;
};
line a[N],dp[N];
ll n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i].st>>a[i].ed;
		a[i].dis=a[i].ed-a[i].st;
	}
	dp[1].st=a[1].dis+a[1].ed-1;
	dp[1].ed=a[1].ed-1;
	for(ll i=2;i<=n;i++)
	{
		dp[i].st=min(dp[i-1].st+abs(a[i].ed-a[i-1].st),dp[i-1].ed+abs(a[i].ed-a[i-1].ed))+a[i].dis+1;
		dp[i].ed=min(dp[i-1].st+abs(a[i].st-a[i-1].st),dp[i-1].ed+abs(a[i].st-a[i-1].ed))+a[i].dis+1;
	}
	cout<<min(dp[n].st+n-a[n].st,dp[n].ed+n-a[n].ed);
	return 0;
}
