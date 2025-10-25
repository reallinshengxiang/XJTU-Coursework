#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[11];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=4;i<=10000;i++)
	{
		ll x=i*i;
		ll t=x;
		memset(a,0,sizeof(a));
		while(x!=0)
		{
			a[x%10]++;
			x=x/10;
		}
		ll flag=1;
		for(ll k=0;k<=9;k++)
		{
			if(a[k]>=2) flag=0;
			if(a[0]!=0) flag=0;
			//if(a[1]==1||a[4]==1||a[9]==1||(a[2]==1&&a[5]==1)||(a[3]==1&&a[6]==1)||(a[5]==1&&a[6]==1&&a[7]==1)) flag=0;
		}
		if(flag) cout<<t<<"\n";
	}
	return 0;
}
