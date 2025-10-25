#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,p;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>p;
	ll pos=0,st=0,ed=0,len=s.size(),ansst=0,ansed=0;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]==p[pos])
		{
			pos++;
			if(pos==1) st=i;
			if(pos==p.size())
			{
				ed=i;
				if(len>ed-st+1)
				{
					len=ed-st+1;
					ansst=st;
					ansed=ed;
				}
				pos=0;
				i=st;
			}
		}
	}
	for(ll i=ansst;i<=ansed;i++) cout<<s[i];
	return 0; 
} 
