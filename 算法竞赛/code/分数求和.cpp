#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
struct fenshu{
	ll fz,fm;
};
fenshu fs[110];
ll n,tt,t,x,fh;
string s;
ll gcd(ll a,ll b)
{
	ll t,r;
	if(a<b) 
	{
		t=a;
		a=b;
		b=t;
	}
	while(a%b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		tt=0;
		t=0;
		if(s[0]=='-') t=1; 
		for(ll j=t;j<=s.size()-1;j++)
		{
			if(s[j]!='/')  tt=tt*10+(s[j]-'0');
			if(s[j]=='/')
			{
				fs[i].fz=tt;
				tt=0;
				if(t==1) fs[i].fz=-fs[i].fz;
			}
		}
		fs[i].fm=tt;
	}
	fs[0].fz=fs[1].fz;
	fs[0].fm=fs[1].fm;
	for(ll i=2;i<=n;i++)
	{
	 	
	    x=gcd(fs[i].fm,fs[0].fm);
	    x=fs[i].fm*fs[0].fm/x;	
		fs[0].fz=fs[0].fz*x/fs[0].fm+fs[i].fz*x/fs[i].fm;
		fs[0].fm=x;
			
		
	}
	if(fs[0].fz<0) fh=-1;
	fs[0].fz=abs(fs[0].fz);
	x=gcd(fs[0].fz,fs[0].fm);
	fs[0].fz=fs[0].fz/x;
	fs[0].fm=fs[0].fm/x;
	x=fs[0].fz/fs[0].fm;
	fs[0].fz=fs[0].fz-x*fs[0].fm;
	if(x==0) 
	{
		if(fs[0].fz==0) cout<<"0";
		else 
		{
			if(fh==-1) cout<<-1*fs[0].fz<<"/"<<fs[0].fm;
			else cout<<fs[0].fz<<"/"<<fs[0].fm;
		}
	} 
	else if(fs[0].fz==0) cout<<x;
	else 
	{
		if(fh==-1) cout<<x<<" "<<-1*fs[0].fz<<"/"<<fs[0].fm;
		else cout<<x<<" "<<fs[0].fz<<"/"<<fs[0].fm;
	}
	return 0;
}
