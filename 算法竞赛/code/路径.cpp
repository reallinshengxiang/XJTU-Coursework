#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2200],x,n; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	x=1;
	cin>>n;
	memset(a,0x7f/3,sizeof(a));
	a[1]=0;
	for(ll i=2;i<=n;i++)
	{
		for(ll j=max(x,i-21);j<=i-1;j++)
		{
			a[i]=min(a[i],a[j]+i*j/__gcd(i,j));
			
		}
	}
    for(ll i=1;i<=n;i++) cout<<a[i]<<"\n";
	return 0;
}
