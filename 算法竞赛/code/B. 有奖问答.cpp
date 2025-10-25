#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=23;i++) ans=ans*2;
	for(ll i=1;i<=13;i++) ans=ans-(1+i)*i/2; 
	cout<<ans; 
	return 0; 
}
