#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,a[5050][5050],x,y,w,r,t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t>>r;
	while(t--)
	{
		cin>>x>>y>>w;
		x++;
		y++;
		a[x][y]=a[x][y]+w;
	}
	for(ll i=1;i<=5001;i++)
	{
		for(ll j=1;j<=5001;j++)  a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	}
	ans=0;
	for(ll i=r;i<=5001;i++)
	{
		for(ll j=r;j<=5001;j++) 
		{
			x=max(i-r,(ll)0);
			y=max(j-r,(ll)0);
			ans=max(ans,a[i][j]-a[x][j]-a[i][y]+a[x][y]);
		}
	}
	cout<<ans;
	return 0;
}
