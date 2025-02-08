#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll a,b,c;
	cin>>a>>b;
	c=__gcd(a,b);
	cout<<c<<" "<<a*b/c<<"\n";
}
