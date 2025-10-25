#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
map<ll,ll> mp[N];
string s1,s2;
ll a,b,ans,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		a=s1[0]*26+s1[1];
		b=s2[0]*26+s2[1];
		ans=ans+mp[b][a];
		if(b==a) ans=ans-mp[b][a];
		mp[a][b]++;
	}
	cout<<ans;
	return 0;
}
