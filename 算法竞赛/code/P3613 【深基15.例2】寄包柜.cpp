#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,q,opt,i,j,k;;
map<ll,ll> mp[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	while(q--)
	{
		cin>>opt;
		if(opt==1)
		{
			cin>>i>>j>>k;
			mp[i][j]=k;
		}
		else if(opt==2)
		{
			cin>>i>>j;
			cout<<mp[i][j]<<"\n";
		}
	}
	return 0; 
} 
