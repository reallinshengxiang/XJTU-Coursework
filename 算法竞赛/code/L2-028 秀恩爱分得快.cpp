#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
ll n,m,a[N],x,k,xb[N];
string s;
map<ll,ll> mp;
ll to_ll(string s)
{
	ll ans=0;
	for(ll i=0;i<s.size();i++) ans=ans*10+(s[i]-'0');
	return ans; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>s;
		if(s[0]=='-') 
		{
			xb[i]=-1;
			a[i]=to_ll(s.substr(1,s.size()-1));			
		}
		else 
		{
			xb[i]=1;
			a[i]=to_ll(s.substr(0,s.size()));
		}
		mp[a[i]]=i;
		cout<<a[i]<<" ";
	}
	for(ll i=1;i<=m;i++)
	{
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			cin>>x;
		//	cout<<x<<"\n";
		}
	}
	
	
	return 0;
}
