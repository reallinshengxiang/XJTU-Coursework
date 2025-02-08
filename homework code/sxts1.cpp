#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100][100];
int main()
{
	ll n,x,y;
	cin>>n;
	ll step=1;
	a[1][1]=1;
	x=1;
	y=1;
	while(step<n*n)
	{
		while(x<n&&a[x+1][y]==0)
		{
			x++;
			step++;
			a[x][y]=step;
		}
		while(y<n&&a[x][y+1]==0)
		{
                        y++;
			step++;
			a[x][y]=step;
		}
		while(x>1&&a[x-1][y]==0)
		{
			x--;
			step++;
			a[x][y]=step;
		}
		while(y>1&&a[x][y-1]==0)
		{
			y--;
			step++;
			a[x][y]=step;
		}
		//cout<<step<<"\n";
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) cout<<setw(5)<<a[i][j]<<" ";
		cout<<"\n";
	}

}
