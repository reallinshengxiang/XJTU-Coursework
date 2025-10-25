#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll ans[N],a[N],pos,sum,n,k,indegree[N];
vector<ll> e[N];
void update(ll step)
{
	if(step>sum) 
	{
		for(ll i=0;i<=step;i++) ans[i]=a[i];
		sum=step;
	}
	ll flag=0;
	if(step==sum)
	{
		for(ll i=0;i<=step;i++)
		{
			if(ans[i]<a[i]) break;
			if(ans[i]>a[i])
			{
				flag=1;
				break;
			}
		}
		if(flag) for(ll i=0;i<=step;i++) ans[i]=a[i];
	}
}
void dfs(ll now,ll step)
{
	a[step]=now;
	if(e[now].size()==0)
	{
		if(step>=sum) update(step);
	}
	for(ll i=0;i<e[now].size();i++)
	{
		ll to=e[now][i];
		dfs(to,step+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=0;i<=n-1;i++)
	{
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll x;
			cin>>x;
			e[i].push_back(x);
			indegree[x]++;
		}
	}
	for(ll i=0;i<=n-1;i++)
	{
		if(indegree[i]==0)
		{
			pos=i;
			break;
		}
	}
	a[0]=ans[0]=pos;
	dfs(pos,0);
	cout<<sum+1<<"\n";
	for(ll i=0;i<=sum;i++) 
	{
		cout<<ans[i];
		if(i!=sum) cout<<" ";
	}
	return 0;
}
