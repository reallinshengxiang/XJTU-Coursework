#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[110][110],sum[110][110],minans=100000;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=100;i++)
	{
		if(i==1)
		{
			a[i][1]=1;
			for(ll j=2;j<=100;j++) a[i][j]=a[i][j-1]+2;
		}
		else for(ll j=1;j<=100;j++) a[i][j]=a[i-1][j]+1;
	}
	for(ll i=1;i<=100;i++)
	{
		for(ll j=1;j<=100;j++) sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	}
	for(ll i=1;i<=100;i++)
	{
		for(ll j=1;j<=100;j++)
		{
			for(ll k=1;k<=i;k++)
			{
				for(ll q=1;q<=j;q++)
				{
					if(sum[i][j]-sum[k-1][j]-sum[i][q-1]+sum[k-1][q-1]==2022) 	minans=(i-k+1)*(j-q+1);
				}
			}
		}
	}
	cout<<minans;
	return 0;
}
