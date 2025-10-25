#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	x=sqrt(n);
	for(ll i=0;i<=x;i++)
	{
		for(ll j=i;j<=x;j++)
		{
			for(ll k=j;k<=x;k++)
			{
				for(ll h=k;h<=x;h++)
			    {
			    	if(i*i+j*j+k*k+h*h==n)
			    	{
			    		cout<<i<<" "<<j<<" "<<k<<" "<<h;
			    		return 0;
					}
				}
			}
		}
	}
	return 0;
}
