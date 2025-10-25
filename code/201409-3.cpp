#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,ss,s1,ss1;
ll n,x,pos;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>x>>n;
	if(x==1)
	{
		while(n--)
		{
			cin>>ss;
			pos=ss.find(s);
			if(pos>=0&&pos<=ss.size()) cout<<ss<<"\n";
		}		
	}
	else
	{
		s1=s;
		for(ll i=0;i<s.size();i++)
		{
			if(s1[i]>='A'&&s1[i]<='Z') s1[i]=s1[i]-'A'+'a';
		}
		while(n--)
		{
			cin>>ss;
			ss1=ss;
			for(ll i=0;i<ss.size();i++) 
			{
				if(ss1[i]>='A'&&ss1[i]<='Z') ss1[i]=ss1[i]-'A'+'a';
			}
			pos=ss1.find(s1);
			if(pos>=0&&pos<=ss1.size()) cout<<ss<<"\n";
		}
	}
	return 0;
}
