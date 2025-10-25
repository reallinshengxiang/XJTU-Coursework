#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,m[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll check(ll year,ll month,ll day)
{
	ll x=year;
	while(x!=0)
	{
		if(x%10==2) return 1;
		x=x/10;
	}
	x=month;
	while(x!=0)
	{
		if(x%10==2) return 1;
		x=x/10;
	}
	x=day;
	while(x!=0)
	{
		if(x%10==2) return 1;
		x=x/10;
	}
	return 0;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll year=1900;year<=9999;year++)
	{
		if(year%400==0||(year%100!=0&&year%4==0)) m[2]=29;
		else m[2]=28;
		for(ll month=1;month<=12;month++)
		{
			for(ll day=1;day<=m[month];day++)
			{
				if(check(year,month,day)) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
// 1994240
