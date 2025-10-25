#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll ans,x,t,n,ss[400040],maxl,l;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	t=n;
	while(t--)
	{
		cin>>s;
		for(ll i=0;i<=s.size()-1;i++) ss[i]=ss[i]^(s[s.size()-1-i]-'0');
		l=s.size();
		maxl=max(maxl,l);
	}
	for(ll i=maxl-1;i>=0;i--) ans=(ans*2%mod+ss[i])%mod;
	cout<<ans;
	return 0;
}
