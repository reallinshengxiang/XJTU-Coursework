#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll mod=1000000000000037;
ll ans,n;
string s[5],mins;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=3;i++) cin>>s[i];
	for(ll i=0;i<=n-1;i++) mins[i]=min(s[1][i],min(s[2][i],s[3][i]));
	for(ll i=0;i<=n-1;i++)	ans=(ans*127+int(mins[i]))%mod;
	cout<<ans;
	return 0;
}
