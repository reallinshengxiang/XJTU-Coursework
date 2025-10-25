#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e3+10;
ll n,m,k,vis[N],a[N],mp[N][N];
vector<ll> ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		mp[x][y]=1;
	}
	cin>>k;
	for(ll i=1;i<=k;i++)
	{
		ll flag=0;
		for(ll j=1;j<=n;j++)
		{
			cin>>a[j];
			for(ll k=1;k<=j-1;k++)
			{
				if(mp[a[j]][a[k]]==1) 
				{
					flag=1;
					break;
				}	
			}
		}
		if(flag) ans.push_back(i-1);
	//	cout<<flag<<"\n";
	}
	for(ll i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i!=ans.size()-1) cout<<" ";
	}
	return 0;
}
