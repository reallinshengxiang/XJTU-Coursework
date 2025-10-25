#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=12;
struct plane{
	ll t,d,l;
};
plane p[N];
ll n,vis[N],flag,T,a[N];
void dfs(ll step,ll lastime)
{
	if(flag==1) return;
	if(step==n+1)
	{
		flag=1;		
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		if(p[i].t+p[i].d<lastime) continue;
		vis[i]=1;
		dfs(step+1,max(lastime,p[i].t)+p[i].l);
		vis[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>p[i].t>>p[i].d>>p[i].l;
		flag=0;
		dfs(1,0);
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}  
	return 0;
}
