#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
unordered_map<string,vector<ll>> mp;
ll n,m,l,sum[100010];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>l;
		for(ll j=1;j<=l;j++)
		{
			cin>>s;
			mp[s].push_back(i);
		}
	}
	cin>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>s;
		memset(sum,0,sizeof(sum));
		for(ll j=0;j<mp[s].size();j++)
		{
			if(sum[mp[s][j]]==0) cout<<mp[s][j]<<" ";
			sum[mp[s][j]]++;
		}
	    cout<<"\n";
	}
	return 0;
}
