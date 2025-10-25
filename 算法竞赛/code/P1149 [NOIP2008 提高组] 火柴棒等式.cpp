#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f[2010]={6,2,5,5,4,5,6,3,7,6},ans,num,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=10;i<=2000;i++)
	{
		num=i;
		while(num)
		{
			f[i]=f[i]+f[num%10];
			num=num/10;
		}
	}
	for(ll i=0;i<=1000;i++)
	{
		for(ll j=0;j<=1000;j++)
		{
			if(f[i]+f[j]+f[i+j]+4==n) ans++;
		}
	}
	cout<<ans;
	return 0;
}
