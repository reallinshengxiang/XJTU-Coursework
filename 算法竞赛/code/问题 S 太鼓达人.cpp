#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=15;
ll k,xx,vis[1<<N][2];
void dfs(ll x)
{
	for(ll i=0;i<=1;i++)
	{
		if(vis[x][i]) continue;
		vis[x][i]=1;
		cout<<i;
		ll y=((x<<1)&xx)|i;
        dfs(y);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k;
	cout<<(1<<k)<<"\n";
	xx=(1<<(k-1))-1;
	dfs(xx);
	return 0;
}
