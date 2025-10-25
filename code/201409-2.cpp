#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll a[N][N],x1,x2,y1,y2,n,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>x1>>y1>>x2>>y2;
		x1++;
		y1++;
		for(ll i=x1;i<=x2;i++)
		{
			for(ll j=y1;j<=y2;j++) a[i][j]=1;
		}
	}
	for(ll i=0;i<=101;i++)
	{
		for(ll j=0;j<=101;j++) ans=ans+a[i][j];
	}
	cout<<ans;
	return 0;
}
