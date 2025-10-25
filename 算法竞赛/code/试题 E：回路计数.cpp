#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[25],vis[25],ans,e[25][25];
void dfs(ll step,ll x)
{
	if(step==22)
	{
		if(e[a[21]][1])
		{
			ans++;
			cout<<ans<<"         ";
			for(ll i=1;i<=21;i++) cout<<a[i]<<" ";
			cout<<"\n";
		}
	}
	for(ll i=1;i<=21;i++)
	{
		if(vis[i]) continue;
		if(!e[x][i]) continue;
		vis[i]=1;
		a[step]=i;
		dfs(step+1,i);
		vis[i]=0;
		
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=21;i++)
	{
        for(ll j=1;j<=21;j++)
	    {
		 	if(i==j) continue;
			if(__gcd(i,j)) e[i][j]=1; 
		}	
	} 
	vis[1]=1;
	a[1]=1;
	dfs(2,1);
	cout<<ans;
	return 0;
}
