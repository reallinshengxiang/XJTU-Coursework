#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,p;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>p;
	a=a%p;
	b=b%p;
	cout<<((a*b)%p);
}
