#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},ans,day;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	day=5; 
	for(ll year=2000;year<=2020;year++)
	{
		
		if((year%4==0&&year%100!=0)||(year%400==0)) a[2]=29;
		else a[2]=28;
		for(ll i=1;i<=12;i++)
		{
			for(ll j=1;j<=a[i];j++)
			{
				day=day%7+1;
				if(j==1||day==1) ans=ans+2;
				else ans++;
				if(year==2020&&i==10&&j==1)
				{
					cout<<day<<" "<<ans;
					break;
				}
			}
		}
	}
	return 0;
}
