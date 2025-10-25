#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c[5],a[10],T,flag;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		flag=1;
		for(ll i=1;i<=3;i++) cin>>c[i];
		for(ll i=1;i<=5;i++) cin>>a[i];
		for(ll i=1;i<=3;i++)
		{
			c[i]=c[i]-a[i];
			if(c[i]<0)
			{
				flag=0;
				break;
			}
		}
		if(!flag)
		{
			cout<<"NO\n";
			continue;
		}
		if(c[1]>=a[4]) c[1]=c[1]-a[4];
		else if(c[1]+c[3]>=a[4]) c[3]=c[3]-(a[4]-c[1]);
		else
		{
			cout<<"NO\n";
			continue;
		}
		if(c[2]>=a[5]) c[2]=c[2]-a[5];
		else if(c[2]+c[3]>=a[5]) c[3]=c[3]-(a[5]-c[2]);
		else
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
	}
	return 0;
}