#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
ll x[10],y,sum,a[10],s[10],n,flag,dp[100],t[10];
double ss;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1)
	{
		flag=0;
		t[1]=5;
		t[2]=10;
		t[3]=20;
		t[4]=50;
		t[5]=100;
		t[6]=200;
		memset(dp,0x7f,sizeof(dp));
		dp[0]=0;
		for(ll i=1;i<=6;i++) 
		{
			cin>>x[i];
			if(x[i]!=0) flag=1;
		}
		if(!flag) break;
		cin>>ss;
		sum=ss*100;
		for(ll i=1;i<=6;i++)
		{
			for(ll j=sum;j>=t[i];j--)
			{
				for(ll k=1;k<=x[i]&&k*t[i]<=j;k++)	dp[j]=min(dp[j],dp[j-t[i]*k]+k);
			}
		}
		cout<<dp[sum]<<"\n";
	 } 
	return 0;
}
