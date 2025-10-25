#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ans,sum;
void dfs(ll x,ll sum,ll step)
{
	if(step==k)
	{
		if(sum==n) ans++;
		return;
	}
	for(ll i=x;i*(k-step)<=n-sum;i++) dfs(i,sum+i,step+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
