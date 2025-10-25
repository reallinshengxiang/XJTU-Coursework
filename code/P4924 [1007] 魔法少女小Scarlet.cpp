#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=550;
ll n,m,a[N][N],b[N][N],cnt,x,y,r,z,num;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) a[i][j]=(i-1)*n+j;
	}
	while(m--)
	{
		cin>>x>>y>>r>>z;
		cnt=1;
		if(z==1)
		{
		    for(ll i=x-r;i<=x+r;i++)
			{
				for(ll j=y-r;j<=y+r;j++) b[x+y-j][y-x+i]=a[i][j];
			}
			for(ll i=x-r;i<=x+r;i++)
			{
				for(ll j=y-r;j<=y+r;j++) a[i][j]=b[i][j];
			}		
		}
		else
		{
			for(ll i=x-r;i<=x+r;i++)
			{
				for(ll j=y-r;j<=y+r;j++) b[x-y+j][y+x-i]=a[i][j];
			}
			for(ll i=x-r;i<=x+r;i++)
			{
				for(ll j=y-r;j<=y+r;j++) a[i][j]=b[i][j];
			}		
		}		
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
