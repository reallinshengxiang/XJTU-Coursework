#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10,M=110;
vector<ll> ans;
ll n,m,w[N],dp[M],vis[N][M],flag;
bool cmp(ll x,ll y)
{
	if(x>y) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>w[i];
	sort(w+1,w+n+1,cmp);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=m;j>=w[i];j--) 
		{
			if(dp[j]<=dp[j-w[i]]+w[i]) vis[i][j]=1,dp[j]=dp[j-w[i]]+w[i];
		}
	}
	if(m!=dp[m])
	{
		cout<<"No Solution";
		return 0;
	}
	ll sum=m;
	ll step=n;
	while(sum!=0)
	{
		if(vis[step][sum])
		{
			sum=sum-w[step];
			ans.push_back(w[step]);
		}
		step--;
	}
	for(ll i=0;i<ans.size();i++) 
	{
		if(!flag)
		{
			flag=1;
			cout<<ans[i];
		}
		else cout<<" "<<ans[i];
	}
	return 0; 
}
