#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,x,y,z,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		x=n-1;
		y=n*(n-2);
		z=__gcd(x,y);
		x=x/z;
		y=y/z;
		cout<<x<<" "<<y<<"\n";
	}
	return 0;
}
