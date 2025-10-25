#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll c[6][6]={
	{0,0,0,0,0,0},
	{0,5,-1,-2,-1,-3},
	{0,-1,5,-3,-2,-4},
	{0,-2,-3,5,-2,-2},
	{0,-1,-2,-2,5,-1},
	{0,-3,-4,-2,-1,0}
};
ll a[N],b[N],n1,n2,dp[N][N];
string s1,s2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n1>>s1>>n2>>s2;
    for(ll i=1;i<=n1;i++) 
    {
    	if(s1[i-1]=='A') a[i]=1;
    	else if(s1[i-1]=='C') a[i]=2;
    	else if(s1[i-1]=='G') a[i]=3;
    	else if(s1[i-1]=='T') a[i]=4;
	}
	for(ll i=1;i<=n2;i++) 
    {
    	if(s2[i-1]=='A') b[i]=1;
    	else if(s2[i-1]=='C') b[i]=2;
    	else if(s2[i-1]=='G') b[i]=3;
    	else if(s2[i-1]=='T') b[i]=4;
	}
	for(ll i=1;i<=n1;i++) dp[i][0]=dp[i-1][0]+c[a[i]][5];
	for(ll i=1;i<=n2;i++) dp[0][i]=dp[0][i-1]+c[5][b[i]];
	for(ll i=1;i<=n1;i++)
	{
		for(ll j=1;j<=n2;j++) dp[i][j]=max(dp[i-1][j-1]+c[a[i]][b[j]],max(dp[i-1][j]+c[a[i]][5],dp[i][j-1]+c[5][b[j]]));
	}
	cout<<dp[n1][n2];
	return 0;
}
