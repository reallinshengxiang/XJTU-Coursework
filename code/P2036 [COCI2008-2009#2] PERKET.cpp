#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,s[11],b[11],ans=0x7f7f7f7f7f7f;
void dfs(ll step,ll sd,ll kd)
{
	if(step>n)
	{
		if(sd==1&&kd==0) return;
		ans=min(abs(sd-kd),ans);
		return;
	}
	dfs(step+1,sd*s[step],kd+b[step]);
	dfs(step+1,sd,kd);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>s[i]>>b[i];
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
