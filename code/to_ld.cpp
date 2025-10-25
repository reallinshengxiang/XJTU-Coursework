#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#pragma GCC optimize(2)
const ll N=5*56*56+1; 
string s,s1;
ll num,sum,flag=1,eps=2,lst;
ld a[N];
ld to_ld(string ss)
{
	ll len=ss.size(),pos=0,pp=0,cishu;
	ld ans=0,ans1=0,qq=1;
	for(ll i=0;i<=len-1;i++)
	{
		if(ss[i]=='.') 
		{
			pos=i;
			break;
		}
	}
	for(ll i=0;i<=len-1;i++) 
	{
		if(ss[i]=='e') 
		{
			pp=i;
			break;
		}
	}
	if(pp==0)
	{
		cishu=len-1-pos;
		for(ll i=0;i<=pos-1;i++) ans=ans*10+(ss[i]-'0');
		for(ll i=pos+1;i<=len-1;i++) ans1=ans1*10+(ss[i]-'0');
		while(cishu) ans1=ans1/10,cishu--;
		ans=ans+ans1;
	}
	else
	{
		cishu=pp-1-pos;
		for(ll i=0;i<=pos-1;i++) ans=ans*10+(ss[i]-'0');
		for(ll i=pos+1;i<=pp-1;i++) ans1=ans1*10+(ss[i]-'0');
		while(cishu) ans1=ans1/10,cishu--;
		ans=ans+ans1;
		ll mici=0;
		for(ll i=pp+2;i<=len-1;i++) mici=mici*10+(ss[i]-'0');
		for(ll i=1;i<=mici;i++) qq=qq*10;
		if(ss[pp+1]=='+') ans=ans*qq;
		else ans=ans/qq;
	}
	return ans;
}
int main()
{
	while(1)
	{
		cin>>s;
	    cout<<to_ld(s);
	}	
} 
