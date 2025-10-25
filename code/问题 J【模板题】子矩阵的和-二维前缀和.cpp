#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[1010][1010],s[1010][1010],q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>a[i][j];
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	}
	ll x1,x2,y1,y2;
	while(q--)
	{
		cin>>x1>>y1>>x2>>y2;
		cout<<s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]<<"\n";
	}
	return 0;
}
