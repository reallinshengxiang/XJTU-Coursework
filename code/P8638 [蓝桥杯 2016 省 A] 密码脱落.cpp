#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
char a[N],b[N];
ll len,dp[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a;
	len=strlen(a);
	for(ll i=0;i<=len-1;i++) b[i]=a[len-1-i];
	for(ll i=1;i<=len;i++)
	{
		for(ll j=1;j<=len;j++)
		{
			if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<len-dp[len][len];
	return 0;
}
