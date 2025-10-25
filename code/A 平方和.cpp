#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,flag;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		string s;
		s=to_string(i);
		flag=0;
		for(ll j=0;j<s.size();j++)
		{
			if(s[j]=='2'||s[j]=='0'||s[j]=='1'||s[j]=='9') flag=1;
		}
		if(flag) ans=ans+i*i;
	}
	cout<<ans;
	return 0;
}
