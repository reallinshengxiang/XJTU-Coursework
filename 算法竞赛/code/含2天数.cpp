#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll ans,x;
ll find(ll x)
{
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
	for(ll i=1900;i<=9999;i++)
	{
		for(ll j=1;j<=12;j++)
		{
			if(i%400==0||(i%4==0&&i%100!=0)) a[2]=29;
			else a[2]=28;
			x=a[j];
			for(ll k=1;k<=x;k++)
			{
				ll xx=i*10000+j*100+k;
				if(find(xx)) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
