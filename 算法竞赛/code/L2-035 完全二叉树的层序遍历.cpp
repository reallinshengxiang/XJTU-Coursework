#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll t[N],n;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;} 
void dfs(ll p)
{
	if(t[p]==-1)
	{
		dfs(ls(p));
	    dfs(rs(p));
	    cin>>t[p];
	}	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<ll,vector<ll>,greater<ll>> q;
	cin>>n;
	for(ll i=1;i<=n;i++) t[i]=-1; 
	dfs(1);	
	for(ll i=1;i<=n;i++)
	{
		cout<<t[i];
		if(i!=n) cout<<" ";
	}
	return 0;
}
