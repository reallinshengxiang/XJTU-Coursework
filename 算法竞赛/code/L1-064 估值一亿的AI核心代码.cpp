#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct qj{
	ll st,ed;
};
qj q[N];
ll n,flag,st,ed,cnt;
string ss[N],s,fh[N];
ll check(char ch)
{
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin.get();
		for(ll i=0;i<N;i++) ss[i]=fh[i]="";
		getline(cin,s);
		cout<<s<<"\n";
		for(ll i=0;i<s.size();i++)
		{
			if(s[i]=='?') s[i]='!';
			if(s[i]>='A'&&s[i]<='Z'&&s[i]!='I') s[i]=char(s[i]+32);
			//if(s[i]=='i') s[i]='I';
		} 
		flag=0;
		cnt=0;
		ll len=s.size();
		for(ll i=0;i<s.size();i++)
		{
			if(check(s[i])&&!flag) 
			{
				q[++cnt].st=i;
				flag=1;
				continue;
			}
			if(!check(s[i])&&flag)
			{
				q[cnt].ed=i-1;
				flag=0;
				continue; 
			} 
	    }
	    if(check(s[len-1])&&flag) q[cnt].ed=len-1;
	    for(ll i=1;i<=cnt;i++)	ss[i]=s.substr(q[i].st,q[i].ed-q[i].st+1);
	    for(ll i=1;i<cnt;i++)
	    {
	    	st=ed=q[i+1].st-1;
	    	for(ll j=q[i].ed+1;j<=q[i+1].st-1;j++)
	    	{
	    		if(s[j]!=' ')
	    		{
	    			st=j;
	    			break;
				}
			}
			fh[i]=s.substr(st,ed-st+1);
		}
		st=ed=len-1;
		flag=0;
		for(ll j=q[cnt].ed+1;j<=len-1;j++)
		{
			if(!check(s[j])) flag=1;
			if(s[j]!=' ')
	    	{
	    		st=ed=j;
	    		break;
			}
		}
		if(flag) fh[cnt]=s.substr(st,ed-st+1);
		//for(ll i=1;i<=cnt;i++) cout<<ss[i]<<"000"<<fh[i]<<"000";
		//cout<<"\n"; 
		cout<<"AI: ";
	    for(ll i=1;i<=cnt-1;i++)
	    {	    	
	    	if(ss[i]=="can"&&ss[i+1]=="you") ss[i]="I",ss[i+1]="can",i++;
	    	else if(ss[i]=="could"&&ss[i+1]=="you") ss[i]="I",ss[i+1]="could",i++;
	    	else if(ss[i]=="I"||ss[i]=="me") ss[i]="you";
		}
		if(ss[cnt]=="I"||ss[cnt]=="me") ss[cnt]="you";
		for(ll i=1;i<=cnt;i++) cout<<ss[i]<<fh[i];
	    cout<<"\n";
	}
	return 0;
}
