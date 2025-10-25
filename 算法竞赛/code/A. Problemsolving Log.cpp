#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,ans,len;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>len>>s;
		unordered_map<ll,ll> mp;
		ans=0;
		for(ll i=0;i<=len-1;i++) mp[s[i]-'A']++;
		for(ll i=0;i<=26;i++)
		{
			if(mp[i]>=i+1) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
