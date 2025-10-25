#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,m,pos,sum;
map<ll,ll> mp;
vector<ll> k[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>sum;
		for(ll j=1;j<=sum;j++) 
		{
			ll pp;
			cin>>pp;
			k[i].push_back(pp);
		}
	}
	pos=1;
	while(m--)
	{
		ll opt,j;
		cin>>opt>>j;
		if(opt==0) pos=k[pos][j-1];
		else if(opt==1)
		{
			mp[j]=pos;
			cout<<pos<<"\n";
		}
		else pos=mp[j];
	}
	cout<<pos;
	return 0; 
}
