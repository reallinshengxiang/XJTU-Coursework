#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll w,h,r,n,a[N][N],sum,x,y;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>w>>h>>n>>r;
	for(ll ii=1; ii<=n; ii++)
	{
		cin>>x>>y;
		for(ll i=0; i<=w; i++)
		{
			for(ll j=0; j<=h; j++)
			{
				if(a[i][j]) continue;
				if((i-x)*(i-x)+(j-y)*(j-y)<=r*r) a[i][j]=1;
			}
		}
	}
	for(ll i=0; i<=w; i++)
	{
		for(ll j=0; j<=h; j++) sum=sum+a[i][j];
	}
	cout<<sum;
	return 0;
}
