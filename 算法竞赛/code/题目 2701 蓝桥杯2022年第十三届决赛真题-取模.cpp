#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T;
	cin>>T;
	while(T--)
	{
		ll n,m;
		cin>>n>>m;
		ll flag=0;
		for(ll x=1;x<m&&!flag;x++)
		{
			for(ll y=x+1;y<=m&&!flag;y++)
			{
				if(n%x==n%y) 
				{
					flag=1;
					cout<<"Yes\n";
					break;
				}
			}
		}
		if(!flag) cout<<"No\n";
	}
	return 0;
} 
