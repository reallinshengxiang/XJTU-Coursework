#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll k,n,m,num;
vector<string> ans;
string s;
map<string,ll> vis,vv;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>k;
		if(k==1) cin>>s;
		else
		{
			for(ll j=1;j<=k;j++)
			{
				cin>>s;
				vis[s]=1;
			}
		} 
	}
	cin>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>s;
		if(!vis[s]&&!vv[s])
		{
			ans.push_back(s);
			num++;
			vv[s]=1;
		}
	}
	if(!num) 
	{
		cout<<"No one is handsome";
		return 0;
	}
	for(ll i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i!=ans.size()-1) cout<<" ";
	}
	return 0;
}
