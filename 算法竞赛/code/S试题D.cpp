#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#pragma GCC optimize(2)
const ll N=1e5+10;
vector<ll> ea[N],eb[N];
ll n,m,xla[N],a[N],b[N],ans,cnt;
void dfsb(ll now,ll step,ll fa)
{
	if(eb[now].size()==1&&eb[now][0]==fa) return;
	if(step>=cnt) return;  
	for(ll i=0;i<eb[now].size();i++)
	{
		ll to=eb[now][i];
		if(to==fa) continue;
		if(b[to]==xla[step+1]) 
		{
			ans=max(ans,step+1);
			dfsb(to,step+1,now);
		}
	}
}
void dfsa(ll now,ll step,ll fa)
{
	//cout<<now<<"\n";
	if(ea[now].size()==1&&ea[now][0]==fa) 
	{
		cnt=step;
	//	for(ll i=1;i<=cnt;i++) cout<<xla[i]<<" ";
	//	cout<<"\n";
		dfsb(1,1,-1);
		return;
	}
	for(ll i=0;i<ea[now].size();i++)
	{
	    ll to=ea[now][i];
	    if(to==fa) continue;
		xla[step+1]=a[ea[now][i]];
		dfsa(to,step+1,now);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=m;i++) cin>>b[i];
	for(ll i=1;i<=n-1;i++)
	{
		ll x,y;
		cin>>x>>y;
		ea[x].push_back(y);
		ea[y].push_back(x);
	}
	for(ll i=1;i<=m-1;i++)
	{
		ll x,y;
		cin>>x>>y;
		eb[x].push_back(y);
		eb[y].push_back(x);
	}
	if(a[1]!=b[1])
	{
		cout<<0;
		return 0;
	}
	xla[1]=a[1];
	ans=1;
	dfsa(1,1,-1);
	cout<<ans;
	return 0; 
}
/*
9 5
1 2 2 2 3 3 3 3 4
1 2 3 4 5
1 2
1 3
4 1
2 5
3 7
4 6
4 8
8 9
1 2
2 3
3 4
4 5
*/

