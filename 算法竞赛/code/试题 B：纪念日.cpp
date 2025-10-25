#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},ans,ans1,ans2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1921;i<=2020;i++)
	{
		if((i%4==0&&i%100!=0)||(i%400==0)) a[2]=29;
		else a[2]=28;
		for(ll j=1;j<=12;j++)
		{
			for(ll k=1;k<=a[j];k++) 
			{
				ans++;
				if(i==1921&&j==7&&k==23) ans1=ans,cout<<ans1<<"\n";
				if(i==2020&&j==7&&k==1) ans2=ans,cout<<ans2<<"\n";
			}
		}
	}
	cout<<(ans2-ans1)*24*60;
	return 0;
}
