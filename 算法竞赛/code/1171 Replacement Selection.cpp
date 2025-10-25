#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10,inf=1e10;
struct node{
	ll val,run;
	bool operator < (const node &a) const
	{
		if(run>a.run) return 1;
		if(run==a.run&&val>a.val) return 1;
		return 0; 
	}
}; 
vector<ll> e[N];
ll run,cnt,n,m,a[N],pos,vis[N];
priority_queue<node> dq;
ll the_min_vis()
{
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i]) return i;
	}
	return n+1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	run=1;
	for(ll i=1;i<=m;i++)
	{
		cnt++;
		vis[i]=i;
		dq.push((node){a[i],1});
	}
	pos=m+1;
	while(1)
	{
		//pos=the_min_vis();
		//cout<<pos<<"\n";
		if(pos>n) break;
		ll x=dq.top().val;
		if(dq.top().run==run) 
		{
			e[run].push_back(x);
			vis[pos]=1;
			if(a[pos]<x) dq.push((node){a[pos],run+1});
			else dq.push((node){a[pos],run});
			dq.pop();
			pos++;
		}
		else run++;
	}
	//sort(dq+1,dq+m+1,cmp);
	while(!dq.empty())
	{
		node p=dq.top();
		e[p.run].push_back(p.val),run=max(run,p.run);
		dq.pop();
	}
	for(ll i=1;i<=run;i++)
	{
		for(ll j=0;j<e[i].size();j++)
		{
			if(j!=0) cout<<" ";
			cout<<e[i][j];
		}
		cout<<"\n";
	}
	return 0;
 } 
