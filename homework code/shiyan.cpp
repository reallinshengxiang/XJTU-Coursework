#include<bits/stdc++.h>
using namespace std;
string s;
double tt,x;
long long i=0,st[100],t;
int main()
{
	cin>>s;
	while(s[i]!='@')
	{
		if(s[i]>='0'&&s[i]<='9')	tt=tt*10+s[i]-'0';
		else if(s[i]=='.')
		{
			t++;
			st[t]=tt;
			tt=0;
		}
		else if(s[i]=='+')
		{
			x=st[t];
			t--;
			st[t]=st[t]+x;
		}
		else if(s[i]=='-')
		{
			x=st[t];
			t--;
			st[t]=st[t]-x;
		}
		else if(s[i]=='*')
		{
			x=st[t];
			t--;
			st[t]=st[t]*x;
		}
		else if(s[i]=='/')
		{
			x=st[t];
			tt--;
			st[t]=st[t]/x;
		}
		i++;
	}
	cout<<st[1]<<"\n";
}
