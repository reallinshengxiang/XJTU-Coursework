#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll ans=1;
	for(ll i=1;i<=2021;i=i+2) ans=ans*i%100000;
	cout<<ans;
	return 0;
}
