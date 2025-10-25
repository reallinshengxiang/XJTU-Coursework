#include<bits/stdc++.h>
using namespace std;
#define ll int
#define rll register int
const ll N=2e6+10;
map<ll,vector<ll>> mp;
ll ans[N],a[22],n,s,cnt;
void dfs1(ll step,ll sum,ll now)
{
	if(step>n/2)
	{
		mp[sum].push_back(now);
		return;
	}
	dfs1(step+1,sum+a[step],now|(1<<(step-1)));
	dfs1(step+1,sum-a[step],now|(1<<(step-1)));
	dfs1(step+1,sum,now);
}
void dfs2(ll step,ll sum,ll now)
{
	if(step>n)
	{
		if(mp.count(sum))
		{
			for(rll i=0;i<mp[sum].size();i++) ans[mp[sum][i]|now]=1;
		}
		return;
	}
	dfs2(step+1,sum+a[step],now|(1<<(step-1)));
	dfs2(step+1,sum-a[step],now|(1<<(step-1)));
	dfs2(step+1,sum,now);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(rll i=1;i<=n;i++) cin>>a[i];
	dfs1(1,0,0);
	dfs2(n/2+1,0,0);
	for(rll i=1;i<=(1<<n);i++) s=s+ans[i];
	cout<<s;
	return 0;
}
