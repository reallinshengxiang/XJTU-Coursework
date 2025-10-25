#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	if(b%a!=0) 
	{
		cout<<0;
		return 0;
	}
	b=b/a;
	for(ll i=1;i<=b;i++)
	{
		if(b%i) continue;
		if(__gcd(i,b/i)==1) ans++;
	}
	cout<<ans;
	return 0;
}
