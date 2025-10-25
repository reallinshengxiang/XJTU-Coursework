#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10;
ll n,x,vis[N],cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) 
	{
		cin>>x;
		if(x<=0||x>1e5) continue;
		vis[x]=1;
		cnt++;
	}
	for(ll i=1;i<=cnt;i++)
	{
		if(!vis[i])
		{
			cout<<i;
			return 0;
		}
	}
	cout<<cnt+1;
	return 0;
 } 
