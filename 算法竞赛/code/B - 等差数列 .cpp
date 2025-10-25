#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a1,a2,n,d;
	cin>>a1>>a2>>n;
	cout<<(a1+a1+(n-1)*(a2-a1))*n/2;
	return 0;
}


