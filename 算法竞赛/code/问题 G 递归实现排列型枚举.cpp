#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[11],vis[11],n;
void dfs(ll step)
{
	if(step==n+1)
	{
		for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<"\n";
		return; 
	}
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
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
	cin>>n;
	dfs(1); 
	return 0;
}
