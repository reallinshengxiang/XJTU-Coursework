#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e6;
ll n,m,k,num,c[22],x,cnt,ff[10010],dp[10010][250],b[10001][10001],ans1,ans2; 
ll panduan1(ll x)
{
	for(ll i=m-1;i>=1;i--)
	{
		if(((x%c[i+1])/c[i])==((x%c[i])/c[i-1])) return 0;
	}
	return 1;
}
ll panduan2(ll x,ll y)
{
	for(ll i=m-1;i>=0;i--)
	{
		if(((x%c[i+1])/c[i])==((y%c[i+1])/c[i])) return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	c[0]=1;
	num=0;
	for(ll i=1;i<=m;i++)
	{
		cin>>x;
		num=num*3+x-1;
		c[i]=c[i-1]*3;
	}
	if(!panduan1(num))
	{
		cout<<"0";
		return 0;
	}
	for(ll i=0;i<=c[m]-1;i++)
	{
		if(panduan1(i))
		{
			cnt++;
			ff[cnt]=i;
		}
		if(num==i) dp[0][cnt]=1;
 	}
 	for(ll i=1;i<=cnt;i++)
 	{
 		for(ll j=1;j<=cnt;j++)  b[i][j]=panduan2(ff[i],ff[j]);
    }
    ll xx=min(n-k,k-1);
    ll yy=max(n-k,k-1);
    for(ll i=1;i<=yy;i++)
    {
    	for(ll j=1;j<=cnt;j++)
    	{
    		for(ll k=1;k<=cnt;k++)
    		{
    			if(b[j][k]) dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
			}
		}
	}
	ans1=ans2=0;
	for(ll i=1;i<=cnt;i++)
	{
		ans1=(ans1+dp[xx][i])%mod;
		ans2=(ans2+dp[yy][i])%mod;
	}	
	cout<<((ans1*ans2)%mod);
	return 0;
}
