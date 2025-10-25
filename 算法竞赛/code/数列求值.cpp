#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x1=1,x2=1,x3=1,ansi,n;
	cin>>n;
	for(ll i=4;i<=n;i++)
	{
		ansi=(x1+x2+x3)%10000;
		x1=x2;
		x2=x3;
		x3=ansi;
	} 
	cout<<ansi;
	return 0;
}
