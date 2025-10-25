#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
char s[110];
ll dp[N][N],num[N],n;
ll check(ll l,ll r,ll len){
    for(ll i=l;i<=r;i++)
    {
    	 if(s[i]!=s[(i-l)%len+l])return 0;
	}      
    return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	for(ll i=0;i<=9;i++) num[i]=1;
	for(ll i=10;i<=99;i++) num[i]=2;
	num[100]=3;
	memset(dp,127,sizeof(dp));
	for(ll i=1;i<=n;i++) dp[i][i]=1;
	for(ll len=2;len<=n;len++)
	{
		for(ll i=1;i<=n-len+1;i++)
		{
			ll j=i+len-1;
			for(ll k=i;k<=j-1;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			for(ll k=i;k<=j-1;k++)
			{
				ll xx=k-i+1;
				if(len%xx!=0) continue;
				if(check(i,j,xx))	dp[i][j]=min(dp[i][j],dp[i][k]+2+num[len/xx]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
} 
