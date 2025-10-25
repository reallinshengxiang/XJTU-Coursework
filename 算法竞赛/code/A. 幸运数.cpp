#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,t,a[15],x,sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=100000000;i++) 
	{
		x=i;
		t=0;
		while(x!=0)
		{
			t++;
			a[t]=x%10;
			x=x/10;
		}
		if(t%2==0)
		{
			sum=0;
			for(ll j=1;j<=t/2;j++) sum=sum+a[j];
			for(ll j=t/2+1;j<=t;j++) sum=sum-a[j];
			if(sum==0)	ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
4430091
/ 
