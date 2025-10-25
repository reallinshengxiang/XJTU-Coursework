#include<bits/stdc++.h>
using namespace std;
#define ll long long
string ss,s,temp,tt,t,semp;
ll w,lastline,kh,ans,pos,step,cnt,num,flag,pp,ff,xx;
ll check1(string s)
{
	ll pos1=0,pos2=s.size()-1,ansx=0;
	for(ll i=0; i<s.size(); i++)
	{
		if(s[i]!=' ')
		{
			pos1=i;
			break;
		}
	}
	for(ll i=s.size()-1; i>=0; i--)
	{
		if(s[i]!=' ')
		{
			pos2=i;
			break;
		}
	}
	for(ll i=pos1; i<=pos2; i++)
	{
		if(i+w-1<pos2)
		{
			ansx++;
			i=i+w-1;
			while(s[i+1]==' ') i++;
		}
		else i=pos2,ansx++;
	}
	return ansx;
}
ll check2(string s)
{
	ll pos1=0,pos2=s.size()-1,ansx=0;
	for(ll i=0; i<s.size(); i++)
	{
		if(s[i]!=' ')
		{
			pos1=i;
			break;
		}
	}
	for(ll i=s.size()-1; i>=0; i--)
	{
		if(s[i]!=' ')
		{
			pos2=i;
			break;
		}
	}
	w=w-3;
	for(ll i=pos1; i<=pos2; i++)
	{
		if(i+w-1<pos2)
		{
			ansx++;
			i=i+w-1;
			while(s[i+1]==' ') i++;
		}
		else i=pos2,ansx++;
	}
	return ansx;
}
ll xiangmu()
{
	ll pp=0,len=s.size();
	t="";
	for(ll i=2;i<ss.size();i++) if(ss[i]==' ') pp++;
	if(pp>=ss.size()-2) t="";
	else
	{
		ss=ss.substr(2,len-2);
		ll pos1,pos2;
		for(ll i=0; i<ss.size(); i++)
		{
			if(ss[i]!=' ')
			{
				pos1=i;
				break;
			}
		}
		for(ll i=ss.size()-1; i>=0; i--)
		{
			if(ss[i]!=' ')
			{
				pos2=i;
				break;
			}
		}
		ss=ss.substr(pos1,pos2-pos1+1);
		t=ss;
	} 
	while(getline(cin,ss))
	{
		ll len=ss.size(),pos1,pos2;
		if(len<=1) return 0;
		if(!(ss[0]==' '&&ss[1]==' ')) 
		{
			cout<<t<<"\n";
			ff=0;
			ans=ans+check2(t);
			return 0;
		}
		ss=ss.substr(2,len-2);
		for(ll i=0;i<ss.size();i++) if(ss[i]==' ') pp++;
		if(pp>=len-2)
		{
			cout<<t<<"\n";
			ans=ans+check2(t);
			ff=0;
			return 1;
		}
		for(ll i=0; i<ss.size(); i++)
		{
			if(ss[i]!=' ')
			{
				pos1=i;
				break;
			}
		}
		for(ll i=ss.size()-1; i>=0; i--)
		{
			if(ss[i]!=' ')
			{
				pos2=i;
				break;
			}
		}
		if(pos1>=pos2) 
		{
			cout<<t<<"\n";
			ans=ans+check2(t);
			ff=0;
			return 1;
		}
		else
		{
			ss=s.substr(pos1,pos2-pos1+1);
			t=t+" "+ss;
		}		
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>w;
	lastline=0;
	cin.get();
	lastline=0;
	while(getline(cin,ss))
	{
		ll pos1=0,pos2=ss.size()-1,pp=0;
		if(ss[0]=='*'&&ss[1]==' ') ff=1;
		if(ff) 	xx=xiangmu();
		if(xx==1) continue;
		for(ll i=0; i<ss.size(); i++) if(ss[i]==' ') pp++;
		for(ll i=0; i<ss.size(); i++)
		{
			if(ss[i]!=' ')
			{
				pos1=i;
				break;
			}
		}
		for(ll i=ss.size()-1; i>=0; i--)
		{
			if(ss[i]!=' ')
			{
				pos2=i;
				break;
			}
		}
		if(pos1>pos2||pp==ss.size())
		{
			if(lastline!=0)
			{
				lastline=0;
				ans=ans+check1(s)+1;
				flag=0;
			}
			continue;
		}
		ss=ss.substr(pos1,pos2-pos1+1);
		if(lastline==0)
		{
			s=ss;
			flag=1;
		}
		else
		{
			temp=s;
			s=temp+" "+ss;
			flag=1;
		}
		lastline=1;
	}
	if(flag) ans=ans+check1(s)+1;
	cout<<ans-1;
	return 0;
}



























/*
4
asjcaojca
aaa
a
*/

/*
10
CSP

CSP is
a real realrealrealrealreal
     competition.


Come   and   join   us


*/

/*
10
* CSP

*   CSP is
  * a real
     competition.
*
  * Come!   and   join.
*Tel:
* 12345
*
*/

/*
4
* aaaa
*bbb
  ccc
* dd
    eee
*ff


*/
