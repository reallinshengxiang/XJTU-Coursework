#include<bits/stdc++.h>
using namespace std;
#define ll int
ll n,y,m,d,xx,yy,mm[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string s,ans[4];
ll check(ll y)
{
	if(y%400==0||(y%100!=0&&y%4==0)) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	y=n/10000;
	m=(n%10000)/100;
	d=n%100;
	ll flag1=0,flag2=0,flag=1;
	for(ll i=y;i<=9999&&flag;i++)
	{
		if(i==y) xx=m;
		else xx=1;
		for(ll j=xx;j<=12&&flag;j++)
		{
			if(i==y&&j==m) yy=d;
			else yy=1;
			mm[2]=28;
			if(check(i)) mm[2]=29;
			for(ll k=yy;k<=mm[j]&&flag;k++)
			{
				if(i==y&&j==m&&k==d) continue;
				if(j<=9&&k<=9) s=to_string(i)+"0"+to_string(j)+"0"+to_string(k);
				else if(j<=9) s=to_string(i)+"0"+to_string(j)+to_string(k);
				else if(k<=9) s=to_string(i)+to_string(j)+"0"+to_string(k);
				else s=to_string(i)+to_string(j)+to_string(k);
				if(flag1&&flag2) flag=0;
				if(s[7]==s[0]&&s[6]==s[1]&&s[5]==s[2]&&s[4]==s[3]&&!flag1)
				{
					flag1=1;
					ans[1]=s;
				}
				if(s[0]==s[2]&&s[2]==s[7]&&s[7]==s[5]&&s[1]==s[3]&&s[3]==s[4]&&s[4]==s[6]&&!flag2)
				{
					flag2=1;
					ans[2]=s;
				}
			}
		}
	}
	cout<<ans[1]<<"\n"<<ans[2];
	return 0;
}
