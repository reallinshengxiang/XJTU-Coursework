#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll zh1(string ss)
{
	ll ans=0;
	for(ll i=0;ss[i];i++) ans=ans*10+(ss[i]-'0');
	return ans; 
}
ll zh2(ll x)
{
	ll cnt=0;
	if(x==0) return 1;
	if(x<0) cnt++;
	while(x!=0)
	{
		x=x/10;
		cnt++;
	}
	return cnt;
}
ll T,x,y,opt;
string ss,s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>s;
		if(s=="a") 
		{
		    opt=1;
			string ss,xx,yy;
			cin>>xx>>yy;
			x=zh1(xx);
			y=zh1(yy);
			cout<<x<<"+"<<y<<"="<<x+y<<"\n";
			cout<<xx.size()+2+yy.size()+zh2(x+y)<<"\n";
		}
		else if(s=="b")
		{
		    opt=2;
			string ss,xx,yy;
			cin>>xx>>yy;
			x=zh1(xx);
			y=zh1(yy);
			cout<<x<<"-"<<y<<"="<<x-y<<"\n";
			cout<<xx.size()+2+yy.size()+zh2(x-y)<<"\n";			
		} 
		else if(s=="c") 
		{
		    opt=3;
			string ss,xx,yy;
			cin>>xx>>yy;
			x=zh1(xx);
			y=zh1(yy);
			cout<<x<<"*"<<y<<"="<<x*y<<"\n";
			cout<<xx.size()+2+yy.size()+zh2(x*y)<<"\n";			
		}
		else
		{
			string xx,yy;
			xx=s;
			cin>>yy;
			if(opt==1)
			{
				x=zh1(xx);
			    y=zh1(yy);
			    cout<<x<<"+"<<y<<"="<<x+y<<"\n";
			    cout<<xx.size()+2+yy.size()+zh2(x+y)<<"\n";
			}
			else if(opt==2)
			{
				x=zh1(xx);
			    y=zh1(yy);
			    cout<<x<<"-"<<y<<"="<<x-y<<"\n";
			    cout<<xx.size()+2+yy.size()+zh2(x-y)<<"\n";				
			}
			else
			{
				x=zh1(xx);
			    y=zh1(yy);
			    cout<<x<<"*"<<y<<"="<<x*y<<"\n";
			    cout<<xx.size()+2+yy.size()+zh2(x*y)<<"\n";					
			}
		}
	}
	return 0;
}
