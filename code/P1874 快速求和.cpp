#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=45,N=1e5+10;
ll n,num[M][M],dp[M][N],len;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>n;
	len=s.size();
	for(ll i=1;i<=len;i++)
	{
		for(ll j=i;j<=len;j++) num[i][j]=num[i][j-1]*10+(s[j-1]-'0');
	}
	memset(dp,127,sizeof(dp));
	dp[0][0]=-1;
	for(ll i=1;i<=len;i++)
	{
		for(ll k=0;k<=n;k++)
		{
			for(ll j=i-1;j>=0&&num[j+1][i]<=n;j--)
			{
				if(k>=num[j+1][i]) dp[i][k]=min(dp[i][k],dp[j][k-num[j+1][i]]+1);
			}
		}
	}
	if(dp[len][n]<=len-1) cout<<dp[len][n];
	else cout<<"-1";
	return 0;
}
