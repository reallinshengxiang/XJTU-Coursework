#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
struct point{
	ll l,r;
};
point p[N];
ll ans,n;
void dfs(ll step,ll now)
{
	if(now==0) return;
	ans=max(ans,step);
	dfs(step+1,p[now].l);
	dfs(step+1,p[now].r);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>p[i].l>>p[i].r;
	dfs(1,1);
	cout<<ans;
	return 0;
}
