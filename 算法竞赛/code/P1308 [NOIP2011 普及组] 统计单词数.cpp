#include<bits/stdc++.h>
using namespace std;
#define ll long long
string p,s,ss,s1;
ll cnt,num,pos;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    getline(cin,p);
	for(ll i=0;i<=p.size()-1;i++)
	{
		if(p[i]>='A'&&p[i]<='Z') p[i]=p[i]-'A'+'a';
	}
	getline(cin,s);
	for(ll i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
	}
	for(ll i=0;i<=s.size()-1;i++)
	{
		if(s[i]<'a'||s[i]>'z') 
		{			
			if(ss==p)
			{
				if(num==0) pos=i-p.size();
				num++;
			}
			ss="";
		}
		else 
		{
			s1=ss+s[i];
			ss=s1;
		}
	}
	if(ss==p)
	{
		if(num==0) pos=s.size()-p.size();
		num++;
	}
	if(num==0) cout<<"-1";
	else cout<<num<<" "<<pos;
	return 0;
}
