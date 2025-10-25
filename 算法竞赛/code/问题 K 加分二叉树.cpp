#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll tree[33][33],f[33][33],n;
ll dfs(ll l,ll r)
{
	if(l>r) return 1;
	if(f[l][r]==-1)
	{
		for(ll i=l;i<=r;i++)
		{
			ll now=dfs(l,i-1)*dfs(i+1,r)+f[i][i];
			if(now>f[l][r])
			{
				f[l][r]=now;
				tree[l][r]=i;
			}
		}
	}
	return f[l][r];
}
void print(ll l,ll r)
{
	if(l>r) return;
	cout<<tree[l][r]<<" ";
	print(l,tree[l][r]-1);
	print(tree[l][r]+1,r); 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	memset(f,-1,sizeof(f));
	for(ll i=1;i<=n;i++)
	{
		cin>>f[i][i];
	    tree[i][i]=i;
	}  
	cout<<dfs(1,n)<<"\n";	
	print(1,n);
	return 0;
 } 
