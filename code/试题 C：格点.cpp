#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll ans=0;
	for(ll i=1;i<=2021;i++) 
	{
		for(ll j=1;j<=2021;j++) if(i*j<=2021) ans++;
	}
	cout<<ans;
	return 0;
}
