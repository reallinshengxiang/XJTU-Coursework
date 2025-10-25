#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
vector<ll> e[N];
ll x,pos,n,opt,m;
map<ll,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		e[i].push_back(x);
		for(ll j=1;j<=e[i][0];j++)
		{
			cin>>x;
			e[i].push_back(x);
		}
	}
	pos=1;
	while(m--)
	{
		cin>>opt>>x;
		if(opt==0)	pos=e[pos][x];
		else if(opt==1)
		{
			cout<<pos<<"\n";
			mp[x]=pos;
		}
		else if(opt==2) pos=mp[x];
	}
	cout<<pos;
	return 0;
}
