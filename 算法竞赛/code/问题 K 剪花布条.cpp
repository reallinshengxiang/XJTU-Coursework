#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1010;
ll nex[1010],ans,last;
string s,p;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>s)
	{
		if(s=="#") break;
		cin>>p;
		memset(nex,0,sizeof(nex));
		for(ll i=1;i<p.size();i++)
		{
			ll j=nex[i];
			while(j&&p[i]!=p[j]) j=nex[j];
			if(p[i]==p[j]) nex[i+1]=j+1;
			else nex[i+1]=0;
		}
		ll j=0;
		ans=0;
		last=-1;
		for(ll i=0;i<s.size();i++)
		{
			while(j&&p[j]!=s[i]) j=nex[j];
			if(p[j]==s[i]) j++;
			if(j==p.size())
			{
				if(i-last>=p.size()) 
				{
					ans++;
					last=i;
				}
			}
		}
		cout<<ans<<"\n"; 
	}
	return 0;
}
