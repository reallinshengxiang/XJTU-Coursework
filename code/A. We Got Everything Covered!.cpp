#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=k;j++) cout<<char(96+j);
		}
		cout<<"\n";
	}
	return 0;
}
