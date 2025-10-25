#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll pos,flag;
void print(ll st,ll ed)
{
	while(s[ed]=='0') ed--;
	if(ed<st) cout<<"0";
	else
	{
		for(ll i=ed;i>=st;i--) cout<<s[i];
	}
}
void print1(ll st,ll ed)
{
	while(s[st]=='0') st++;
	if(ed<st) cout<<"0";
	for(ll i=ed;i>=st;i--) cout<<s[i];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	flag=1;
	for(ll i=0;i<=s.size()-1;i++)
	{
		if(s[i]=='.')
		{
			flag=2;
			pos=i;
			break;
		}
		if(s[i]=='/')
		{
			flag=3;
			pos=i;
			break;
		}
		if(s[i]=='%')
		{
			flag=4;
			pos=i;
			break;
		}
	}
	if(flag==1) print(0,s.size()-1);
	else if(flag==2)
	{
		print(0,pos-1);
		cout<<".";
		print1(pos+1,s.size()-1);
	}
	else if(flag==3)
	{
		print(0,pos-1);
		cout<<"/";
		print(pos+1,s.size()-1);
	}
	else
	{
		print(0,pos-1);
		cout<<"%";
	}
	return 0;
}
