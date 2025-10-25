#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rll register long long
const ll N=2e6+10;
ll n,m,ans,cnt1,cnt2,sum1[N],sum2[N],a[42];
void dfs1(ll step,ll sum)
{
	if(sum>m) return;
	if(step>n/2)
	{
		cnt1++;
		sum1[cnt1]=sum;
		return;
	}
	dfs1(step+1,sum+a[step]);
	dfs1(step+1,sum);
}
void dfs2(ll step,ll sum)
{
	if(sum>m) return;
	if(step>n)
	{
		cnt2++;
		sum2[cnt2]=sum;
		return;
	}
	dfs2(step+1,sum+a[step]);
	dfs2(step+1,sum);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	dfs1(1,0);
	dfs2(n/2+1,0);
	sort(sum1+1,sum1+cnt1+1);
	for(rll i=1;i<=cnt2;i++) ans=ans+upper_bound(sum1+1,sum1+1+cnt1,m-sum2[i])-(sum1+1);
	cout<<ans;
	return 0;
}
