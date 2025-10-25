#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,ll> mp;
string ss,s;
ll n,T,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		cnt=0;
		mp.clear();
		for(ll i=0;i<=n-2;i++)
		{
			ss=s.substr(i,2);
			if(!mp[ss])
			{
				cnt++;
				mp[ss]=1;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
