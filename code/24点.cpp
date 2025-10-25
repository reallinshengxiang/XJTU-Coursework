#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll opt[5];
double a[10],ans,x,y,p;
map<ll,ll> mp1,mp2,mp3,mp4;
char fh(ll num)
{
	if(num==1) return '+';
	if(num==2) return '-';
	if(num==3) return '*';
	if(num==4) return '\\';
}
bool check1()
{
	ans=a[1];
	for(ll i=1;i<=3;i++)
	{
		if(opt[i]==1) ans=ans+a[i+1];
		else if(opt[i]==2) ans=ans-a[i+1];
		else if(opt[i]==3) ans=ans*a[i+1];
		else ans=ans/a[i+1];
	}
	if(ans==24) 
	{
		p=0;
		for(ll i=1;i<=4;i++) p=p*31+a[i]; 
		for(ll i=1;i<=3;i++) p=p*31+opt[i];
		if(!mp1[p]) 
		{
			mp1[p]=1;
			return 1;
		}
		return 0;
	}
	return 0;
}
bool check2()
{
	ans=a[2];
	for(ll i=2;i<=3;i++)
	{
		if(opt[i]==1) ans=ans+a[i+1];
		else if(opt[i]==2) ans=ans-a[i+1];
		else if(opt[i]==3) ans=ans*a[i+1];
		else ans=ans/a[i+1];
	}
	if(opt[1]==1) ans=ans+a[1];
	else if(opt[1]==2) ans=-ans+a[1];
	else if(opt[1]==3) ans=ans*a[1];
	else ans=a[1]/ans;
	if(ans==24) 
	{
		p=0;
		for(ll i=1;i<=4;i++) p=p*31+a[i]; 
		for(ll i=1;i<=3;i++) p=p*31+opt[i];
		if(!mp2[p]) 
		{
			mp2[p]=1;
			return 1;
		}
		return 0;
	}
	return 0;
}
bool check3()
{
	x=a[1],y=a[3];
	if(opt[1]==1) x=x+a[2];
	else if(opt[1]==2) x=x-a[2];
	else if(opt[1]==3) x=x*a[2];
	else x=x/a[2];
	if(opt[3]==1) y=y+a[4];
	else if(opt[3]==2) y=y-a[4];
	else if(opt[3]==3) y=y*a[4];
	else y=y/a[4];
	if(opt[2]==1) ans=x+y;
	else if(opt[2]==2) ans=x-y;
	else if(opt[2]==3) ans=x*y;
	else ans=x/y;
	if(ans==24) 
	{
		p=0;
		for(ll i=1;i<=4;i++) p=p*31+a[i]; 
		for(ll i=1;i<=3;i++) p=p*31+opt[i];
		if(!mp3[p]) 
		{
			mp3[p]=1;
			return 1;
		}
		return 0;
	}
	return 0;
}
bool check4()
{
	ans=a[3];
	if(opt[3]==1) ans=ans+a[4];
	else if(opt[3]==2) ans=ans-a[4];
	else if(opt[3]==3) ans=ans*a[4];
	else if(opt[3]==4) ans=ans/a[4];
	for(ll i=2;i>=1;i--)
	{
		if(opt[i]==1) ans=a[i]+ans;
		else if(opt[i]==2) ans=a[i]-ans;
		else if(opt[i]==3) ans=a[i]*ans;
		else ans=a[i]/ans;
	}
	if(ans==24) 
	{
		p=0;
		for(ll i=1;i<=4;i++) p=p*31+a[i]; 
		for(ll i=1;i<=3;i++) p=p*31+opt[i];
		if(!mp4[p]) 
		{
			mp4[p]=1;
			return 1;
		}
		return 0;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=4;i++) cin>>a[i];
	sort(a+1,a+5); 
	ll sum=0;
	do{
		for(opt[1]=1;opt[1]<=4;opt[1]++)
		{
			for(opt[2]=1;opt[2]<=4;opt[2]++)
			{
				for(opt[3]=1;opt[3]<=4;opt[3]++)
				{
					
					if(check1()) cout<<"(("<<a[1]<<fh(opt[1])<<a[2]<<")"<<fh(opt[2])<<a[3]<<")"<<fh(opt[3])<<a[4]<<"=24\n",sum++;				
					if(check2()) cout<<a[1]<<fh(opt[1])<<"(("<<a[2]<<fh(opt[2])<<a[3]<<")"<<fh(opt[3])<<a[4]<<")=24\n",sum++;
					if(check3()) cout<<"("<<a[1]<<fh(opt[1])<<a[2]<<")"<<fh(opt[2])<<"("<<a[3]<<fh(opt[3])<<a[4]<<")=24\n",sum++;
					if(check4()) cout<<a[1]<<fh(opt[1])<<"("<<a[2]<<fh(opt[2])<<"("<<a[3]<<fh(opt[3])<<a[4]<<"))=24\n",sum++;
			    }
			}
		}
	}while(next_permutation(a+1,a+5));
	if(!sum) cout<<"ÖíÍ·Ò»¸ö£¡";
	return 0;
}
