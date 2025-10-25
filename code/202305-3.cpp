#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=4e6+10;
ll n,num;
string ss,s;
char ans[N];
ll toll(char ch)
{
	ll num;
	if(ch>='a') num=ch-'a'+10;
	else num=ch-'0';
	return num;
}
void print()
{
	for(ll i=1;i<=num;i++)
	{
		cout<<ans[i];
		if(i%16==0) cout<<"\n";
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n/8;i++)
	{
		cin>>ss;
		s=s+ss;
	}
	if((n/8)*8!=n)
	{
		cin>>ss;
		s=s+ss; 
	}
	ll len=s.size()-1;
	cout<<"                "<<len<<"\n"; 
	ll sum=0,tt=1,pos;
	for(ll i=0;i<=len;i=i+2)
	{
		ll num1=toll(s[i]);
		ll num2=toll(s[i+1]);
		if(num1>=8)
		{
			sum=sum+(num1*16+num2-128)*tt;
			tt=tt*128;
		}
		else 
		{
			sum=sum+(num1*16+num2)*tt;
			pos=i+2;
			break;
		}
	}
	while(pos<=len)
	{
	     ll num1=toll(s[pos]);
	     ll num2;
		 if(pos+1<=len) num2=toll(s[pos+1]);
		 else break;
	     //cout<<s[pos]<<"   "<<s[pos+1]<<"   "<<pos<<"       ";
	     //cout<<num1<<"  "<<num2<<"\n";
	     pos=pos+2;
		 if(num2%2==0&&(num2/2)%2==0) 
	     {
	     	ll d=num1*4+num2/4+1;
	     	if(d>=61)
	     	{
	     		ll dd=0,tt=1;
	     		for(ll i=1;i<=d-60;i++)
	     		{
	     			ll num1=toll(s[pos]);
	                ll num2=toll(s[pos+1]);
	                pos=pos+2;
	                dd=dd+(num1*16+num2)*tt;
	                tt=tt*256;
				}
				d=dd+1;
			}
			pos--;
			for(ll i=1;i<=d;i++) 
			{
				pos++;
				num++;
				ans[num]=s[pos];
				num++;				
				pos++;
				ans[num]=s[pos];
				//cout<<ans[num-1]<<ans[num];
			}
			pos++;
		 }
		 else if(num2%2==0&&(num2/2)%2==1)
		 {
		 	ll l=num1*4+num2/4+1;
		 	ll o=toll(s[pos])*256+toll(s[pos+3])*16+toll(s[pos+1]);
		 	pos=pos+4;
		 	ll qq=num-2*o;
		 	for(ll i=1;i<=l*2;i++)
		 	{
		 		num++;
		 		ans[num]=ans[qq+(i-1)%(2*o)+1];
		 		//cout<<ans[num];
			}
		 }
		 else
		 {
		 	ll l=((num2/2)%2)*4+((num2/4)%2)*2+((num2/8)%2)+4;
		 	ll o=toll(s[pos])*16+toll(s[pos+1])+(num1/2)*256;
		 	pos=pos+2;
		 	ll qq=num-2*o;
		 	for(ll i=1;i<=2*l;i++)
		 	{
		 		num++;
		 		ans[num]=ans[qq+i];
			}
		 }
	}
	//cout<<"\n";
	print();
	return 0;
}
