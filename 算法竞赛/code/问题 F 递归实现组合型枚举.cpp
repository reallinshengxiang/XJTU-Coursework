#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[30],vis[30],n,m;
void dfs(ll step)
{
	if(step==m+1)
	{
		for(ll i=1;i<=m;i++) cout<<a[i]<<" ";
		cout<<"\n";
		return; 
	}
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i]&&i>a[step-1])
		{
			vis[i]=1;
			a[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	dfs(1); 
	return 0;
}
